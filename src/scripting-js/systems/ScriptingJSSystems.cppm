module;

#include <entt/fwd.hpp>

export module ScriptingJS.Systems;

import Core.EnTTRegistry;
import Core.Scheduler;

export namespace ScriptingJS {

	class ScriptingJSSystems {
	public:
		ScriptingJSSystems(Core::EnTTRegistry&, Core::Scheduler&);
		~ScriptingJSSystems();

		ScriptingJSSystems(ScriptingJSSystems&&) = delete;
		ScriptingJSSystems& operator=(ScriptingJSSystems&&) noexcept = delete;

		ScriptingJSSystems(const ScriptingJSSystems&) = delete;
		ScriptingJSSystems& operator=(const ScriptingJSSystems&) = delete;

		void tick(entt::registry&);

	private:
		Core::EnTTRegistry& mRegistry;
		Core::Scheduler& mScheduler;
		Core::TaskHandle mTickHandle{};
	};

} // namespace ScriptingJS
