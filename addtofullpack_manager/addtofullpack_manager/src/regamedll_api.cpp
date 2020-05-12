// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#include <addtofullpack_manager/regamedll_api.h>
#include <amxx/api.h>
#include <cssdk/dll/api/cs_entity.h>
#include <cssdk/public/interface.h>

/// <summary>
/// </summary>
int RegamedllApi::major_version_ = 0;

/// <summary>
/// </summary>
int RegamedllApi::minor_version_ = 0;

/// <summary>
/// </summary>
GameRules* RegamedllApi::game_rules_ = nullptr;

/// <summary>
/// </summary>
const RegamedllFuncs* RegamedllApi::regamedll_funcs_ = nullptr;

/// <summary>
/// </summary>
RegamedllHookChains* RegamedllApi::regamedll_hook_chains_ = nullptr;

/// <summary>
/// </summary>
RegamedllApiInterface* RegamedllApi::regamedll_api_interface_ = nullptr;

/// <summary>
/// </summary>
bool RegamedllApi::init()
{
	//
	// Load game module.
	//

#ifdef _WIN32
	const auto game_module_path = AmxxApi::build_path_name("dlls/mp.dll");
#else
	const auto game_module_path = AmxxApi::build_path_name("dlls/cs.so");
#endif
	const auto game_module = sys_load_module(game_module_path);

	if (game_module == nullptr) {
		AmxxApi::print_srv_console("[%s] Failed to locate game module.\n\n", AMXX_MODULE_LOG_TAG);
		return false;
	}

	//
	// Get the game interface factory.
	//

	const auto interface_factory = sys_get_factory(game_module);

	if (interface_factory == nullptr) {
		AmxxApi::print_srv_console("[%s] Failed to locate interface factory in game module.\n\n", AMXX_MODULE_LOG_TAG);
		return false;
	}

	//
	// Get the ReGameDll API interface.
	//

	auto ret_code = CreateInterfaceStatus::Failed;
	const auto interface_base = interface_factory(VREGAMEDLL_API_VERSION, &ret_code);

	if (ret_code != CreateInterfaceStatus::Ok || interface_base == nullptr) {
		const auto ret_code_num = static_cast<int>(ret_code);
		AmxxApi::print_srv_console("[%s] Failed to retrieve \"%s\" interface from game module; return code is %d.\n\n",
		                           AMXX_MODULE_LOG_TAG, VREGAMEDLL_API_VERSION, ret_code_num);
		return false;
	}

	regamedll_api_interface_ = reinterpret_cast<RegamedllApiInterface*>(interface_base);

	//
	// Check the ReGameDll version.
	//

	major_version_ = regamedll_api_interface_->get_major_version();
	minor_version_ = regamedll_api_interface_->get_minor_version();

	if (major_version_ != REGAMEDLL_API_VERSION_MAJOR) {
		AmxxApi::print_srv_console("[%s] ReGameDll API major version mismatch; expected %d, real %d.\n",
		                           AMXX_MODULE_LOG_TAG, REGAMEDLL_API_VERSION_MAJOR, major_version_);

		if (major_version_ < REGAMEDLL_API_VERSION_MAJOR) {
			AmxxApi::print_srv_console("[%s] Please update the ReGameDll up to a major version API >= %d.\n\n",
			                           AMXX_MODULE_LOG_TAG, REGAMEDLL_API_VERSION_MAJOR);
		}
		else {
			AmxxApi::print_srv_console("[%s] Please update the %s up to a major version API >= %d.\n\n",
			                           AMXX_MODULE_LOG_TAG, AMXX_MODULE_NAME, REGAMEDLL_API_VERSION_MAJOR);
		}

		return false;
	}

	if (minor_version_ < REGAMEDLL_API_VERSION_MINOR) {
		AmxxApi::print_srv_console("[%s] ReGameDll API minor version mismatch; expected %d, real %d.\n",
		                           AMXX_MODULE_LOG_TAG, REGAMEDLL_API_VERSION_MINOR, minor_version_);

		AmxxApi::print_srv_console("[%s] Please update the ReGameDll up to a minor version API >= %d.\n\n",
		                           AMXX_MODULE_LOG_TAG, REGAMEDLL_API_VERSION_MINOR);

		return false;
	}

	//
	// Safe check cs_entity API interface version.
	//

	if (!check_cs_entity_version(CS_ENTITY_API_INTERFACE_VERSION)) {
		AmxxApi::print_srv_console("[%s]: Interface CCSEntity API version '%s' not found.\n\n",
		                           AMXX_MODULE_LOG_TAG, CS_ENTITY_API_INTERFACE_VERSION);

		return false;
	}

	//
	// Safe check game_rules API interface version.
	//

	if (!check_game_rules_version(GAME_RULES_API_INTERFACE_VERSION)) {
		AmxxApi::print_srv_console("[%s]: Interface CGameRules API version '%s' not found.\n\n",
		                           AMXX_MODULE_LOG_TAG, GAME_RULES_API_INTERFACE_VERSION);

		return false;
	}

	//
	// ReGameDllApi assignment.
	//

	game_rules_ = regamedll_api_interface_->get_game_rules();
	regamedll_funcs_ = regamedll_api_interface_->get_funcs();
	regamedll_hook_chains_ = regamedll_api_interface_->get_hook_chains();

	return true;
}
