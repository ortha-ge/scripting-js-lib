
export module ScriptingJS.SystemsService;

import kangaru;
import Core.EnTTRegistryService;
import Core.SchedulerService;
export import ScriptingJS.Systems;

export namespace ScriptingJS {

	class ScriptingJSSystemsService : public kgr::single_service<ScriptingJSSystems, kgr::dependency<Core::EnTTRegistryService, Core::SchedulerService>>{};

} // Input
