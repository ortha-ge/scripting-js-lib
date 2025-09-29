export module ScriptingJS.Systems;

import Core.Scheduler;
import entt;

export namespace ScriptingJS {

	class ScriptingJSSystems {
	public:
		ScriptingJSSystems(entt::registry&, Core::Scheduler&);
		~ScriptingJSSystems();

		ScriptingJSSystems(ScriptingJSSystems&&) = delete;
		ScriptingJSSystems& operator=(ScriptingJSSystems&&) noexcept = delete;

		ScriptingJSSystems(const ScriptingJSSystems&) = delete;
		ScriptingJSSystems& operator=(const ScriptingJSSystems&) = delete;

		void tick(entt::registry&);

	private:
		entt::registry& mRegistry;
		Core::Scheduler& mScheduler;
		Core::TaskHandle mTickHandle{};
	};

} // namespace ScriptingJS
