
export module Ortha.ScriptingJS.SystemsService;

import kangaru;
import Ortha.Core.EnTTRegistryService;
import Ortha.Core.SchedulerService;
export import Ortha.ScriptingJS.Systems;

export namespace Ortha::ScriptingJS {

	class ScriptingJSSystemsService
		: public kgr::single_service<
			  ScriptingJSSystems, kgr::dependency<Core::EnTTRegistryService, Core::SchedulerService>> {};

} // namespace Ortha::ScriptingJS
