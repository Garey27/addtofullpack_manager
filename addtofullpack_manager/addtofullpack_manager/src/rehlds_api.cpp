// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#include <addtofullpack_manager/rehlds_api.h>
#include <amxx/api.h>
#include <cssdk/public/interface.h>

/// <summary>
/// </summary>
int RehldsApi::major_version_ = 0;

/// <summary>
/// </summary>
int RehldsApi::minor_version_ = 0;

/// <summary>
/// </summary>
const RehldsFuncs* RehldsApi::rehlds_funcs_ = nullptr;

/// <summary>
/// </summary>
RehldsHookChains* RehldsApi::rehlds_hook_chains_ = nullptr;

/// <summary>
/// </summary>
RehldsServerStatic* RehldsApi::rehlds_server_static_ = nullptr;

/// <summary>
/// </summary>
RehldsServerData* RehldsApi::rehlds_server_data_ = nullptr;

/// <summary>
/// </summary>
RehldsFlightRecorder* RehldsApi::rehlds_flight_recorder_ = nullptr;

/// <summary>
/// </summary>
bool RehldsApi::init()
{
	//
	// Load engine module.
	//

#if defined(_WIN32)
	const auto engine_module = sys_load_module("swds.dll");
#else
	const auto engine_module = sys_load_module("engine_i486.so");
#endif

	if (engine_module == nullptr) {
		AmxxApi::print_srv_console("[%s] Failed to locate engine module.\n\n", AMXX_MODULE_LOG_TAG);
		return false;
	}

	//
	// Get the engine interface factory.
	//

	const auto interface_factory = sys_get_factory(engine_module);

	if (interface_factory == nullptr) {
		AmxxApi::print_srv_console("[%s] Failed to locate interface factory in engine module.\n\n", AMXX_MODULE_LOG_TAG);
		return false;
	}

	//
	// Get the ReHLDS API interface.
	//

	auto ret_code = CreateInterfaceStatus::Failed;
	const auto interface_base = interface_factory(VREHLDS_HLDS_API_VERSION, &ret_code);

	if (ret_code != CreateInterfaceStatus::Ok || interface_base == nullptr) {
		AmxxApi::print_srv_console("[%s] Failed to retrieve \"%s\" interface from engine module; return code is %d.\n\n",
		                           AMXX_MODULE_LOG_TAG, VREHLDS_HLDS_API_VERSION, int(ret_code));
		return false;
	}

	const auto api = reinterpret_cast<RehldsApiInterface*>(interface_base);

	//
	// Check the ReHLDS version.
	//

	major_version_ = api->get_major_version();
	minor_version_ = api->get_minor_version();

	if (major_version_ != REHLDS_API_VERSION_MAJOR) {
		AmxxApi::print_srv_console("[%s] ReHLDS API major version mismatch; expected %d, real %d.\n",
		                           AMXX_MODULE_LOG_TAG, REHLDS_API_VERSION_MAJOR, major_version_);

		if (major_version_ < REHLDS_API_VERSION_MAJOR) {
			AmxxApi::print_srv_console("[%s] Please update the ReHLDS up to a major version API >= %d.\n\n",
			                           AMXX_MODULE_LOG_TAG, REHLDS_API_VERSION_MAJOR);
		}
		else {
			AmxxApi::print_srv_console("[%s] Please update the %s up to a major version API >= %d.\n\n",
			                           AMXX_MODULE_LOG_TAG, AMXX_MODULE_NAME, REHLDS_API_VERSION_MAJOR);
		}

		return false;
	}

	if (minor_version_ < REHLDS_API_VERSION_MINOR) {
		AmxxApi::print_srv_console("[%s] ReHLDS API minor version mismatch; expected %d, real %d.\n",
		                           AMXX_MODULE_LOG_TAG, REHLDS_API_VERSION_MINOR, minor_version_);

		AmxxApi::print_srv_console("[%s] Please update the ReHLDS up to a minor version API >= %d.\n\n",
		                           AMXX_MODULE_LOG_TAG, REHLDS_API_VERSION_MINOR);

		return false;
	}

	//
	// RehldsApi assignment.
	//

	rehlds_funcs_ = api->get_funcs();
	rehlds_hook_chains_ = api->get_hook_chains();
	rehlds_server_static_ = api->get_server_static();
	rehlds_server_data_ = api->get_server_data();
	rehlds_flight_recorder_ = api->get_flight_recorder();

	return true;
}
