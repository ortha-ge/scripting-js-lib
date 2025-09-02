module;

#include <utility>

#include <entt/entt.hpp>
#include <quickjs.h>

module ScriptingJS.Systems;

import Core.EnTTRegistry;
import Core.Scheduler;

namespace ScriptingJS {

	constexpr char TestScriptJS[] = R"(
	print('Hello');
)";

	ScriptingJSSystems::ScriptingJSSystems(Core::EnTTRegistry& registry, Core::Scheduler& scheduler)
		: mRegistry{ registry }
		, mScheduler{ scheduler } {

		JSRuntime* runtime = JS_NewRuntime();
		JSContext* context = JS_NewContext(runtime);

		// JSValue result = JS_Eval(context, TestScriptJS, strlen(TestScriptJS), "TestScript.js", JS_EVAL_TYPE_GLOBAL);
		// printf("%s\n", JS_ToCString(context, result));
		// if (JS_IsException(result)) {
		// 	printf("%s\n", JS_ToCString(context, JS_GetException(context)));
		// } else if (JS_IsFunction(context, result)) {
		// 	// JSValue thisValue = JS_DupValue(context, result);
		// 	// JSValue callResult = JS_Call(context, result, thisValue, 0, nullptr);
		// 	// printf("%s\n", JS_ToCString(context, callResult));
		// 	// JS_FreeValue(context, result);
		// 	// JS_FreeValue(context, callResult);
		// } else {
		// 	printf("Failed\n");
		// }
		//
		// JS_FreeValue(context, result);
		JS_RunGC(runtime);

		JS_FreeContext(context);
		JS_FreeRuntime(runtime);

		mTickHandle = mScheduler.schedule([this]() {
		   tick(mRegistry);
		});
	}

	ScriptingJSSystems::~ScriptingJSSystems() {
		mScheduler.unschedule(std::move(mTickHandle));
	}

	void ScriptingJSSystems::tick(entt::registry& registry) {

	}

} // namespace ScriptingJS
