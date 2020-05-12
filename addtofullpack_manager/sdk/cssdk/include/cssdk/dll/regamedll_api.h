// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/common/hook_chains.h>
#include <cssdk/dll/game_rules.h>

/// <summary>
/// </summary>
constexpr auto REGAMEDLL_API_VERSION_MAJOR = 5;

/// <summary>
/// </summary>
constexpr auto REGAMEDLL_API_VERSION_MINOR = 16;

/// <summary>
/// </summary>
constexpr auto VREGAMEDLL_API_VERSION = "VRE_GAMEDLL_API_VERSION001";

// PlayerBase::Spawn hook
using ReHookPlayerSpawn = HookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerSpawn = HookChainClassRegistry<void, PlayerBase>;

// PlayerBase::Precache hook
using ReHookPlayerPrecache = HookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerPrecache = HookChainClassRegistry<void, PlayerBase>;

// PlayerBase::ObjectCaps hook
using ReHookPlayerObjectCaps = HookChainClass<int, PlayerBase>;
using ReHookRegistryPlayerObjectCaps = HookChainClassRegistry<int, PlayerBase>;

// PlayerBase::Classify hook
using ReHookPlayerClassify = HookChainClass<int, PlayerBase>;
using ReHookRegistryPlayerClassify = HookChainClassRegistry<int, PlayerBase>;

// PlayerBase::TraceAttack hook
using ReHookPlayerTraceAttack = HookChainClass<void, PlayerBase, EntityVars*, float, Vector&, TraceResult*, int>;
using ReHookRegistryPlayerTraceAttack = HookChainClassRegistry<void, PlayerBase, EntityVars*, float, Vector&, TraceResult*, int>;

// PlayerBase::TakeDamage hook
using ReHookPlayerTakeDamage = HookChainClass<qboolean, PlayerBase, EntityVars*, EntityVars*, float&, int>;
using ReHookRegistryPlayerTakeDamage = HookChainClassRegistry<qboolean, PlayerBase, EntityVars*, EntityVars*, float&, int>;

// PlayerBase::TakeHealth hook
using ReHookPlayerTakeHealth = HookChainClass<qboolean, PlayerBase, float, int>;
using ReHookRegistryPlayerTakeHealth = HookChainClassRegistry<qboolean, PlayerBase, float, int>;

// PlayerBase::Killed hook
using ReHookPlayerKilled = HookChainClass<void, PlayerBase, EntityVars*, int>;
using ReHookRegistryPlayerKilled = HookChainClassRegistry<void, PlayerBase, EntityVars*, int>;

// PlayerBase::AddPoints hook
using ReHookPlayerAddPoints = HookChainClass<void, PlayerBase, int, qboolean>;
using ReHookRegistryPlayerAddPoints = HookChainClassRegistry<void, PlayerBase, int, qboolean>;

// PlayerBase::AddPointsToTeam hook
using ReHookPlayerAddPointsToTeam = HookChainClass<void, PlayerBase, int, qboolean>;
using ReHookRegistryPlayerAddPointsToTeam = HookChainClassRegistry<void, PlayerBase, int, qboolean>;

// PlayerBase::AddPlayerItem hook
using ReHookPlayerAddPlayerItem = HookChainClass<qboolean, PlayerBase, PlayerItemBase*>;
using ReHookRegistryPlayerAddPlayerItem = HookChainClassRegistry<qboolean, PlayerBase, PlayerItemBase*>;

// PlayerBase::RemovePlayerItem hook
using ReHookPlayerRemovePlayerItem = HookChainClass<qboolean, PlayerBase, PlayerItemBase*>;
using ReHookRegistryPlayerRemovePlayerItem = HookChainClassRegistry<qboolean, PlayerBase, PlayerItemBase*>;

// PlayerBase::GiveAmmo hook
using ReHookPlayerGiveAmmo = HookChainClass<int, PlayerBase, int, const char*, int>;
using ReHookRegistryPlayerGiveAmmo = HookChainClassRegistry<int, PlayerBase, int, const char*, int>;

// PlayerBase::ResetMaxSpeed hook
using ReHookPlayerResetMaxSpeed = HookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerResetMaxSpeed = HookChainClassRegistry<void, PlayerBase>;

// PlayerBase::Jump hook
using ReHookPlayerJump = HookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerJump = HookChainClassRegistry<void, PlayerBase>;

// PlayerBase::Duck hook
using ReHookPlayerDuck = HookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerDuck = HookChainClassRegistry<void, PlayerBase>;

// PlayerBase::PreThink hook
using ReHookPlayerPreThink = HookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerPreThink = HookChainClassRegistry<void, PlayerBase>;

// PlayerBase::PostThink hook
using ReHookPlayerPostThink = HookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerPostThink = HookChainClassRegistry<void, PlayerBase>;

// PlayerBase::UpdateClientData hook
using ReHookPlayerUpdateClientData = HookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerUpdateClientData = HookChainClassRegistry<void, PlayerBase>;

// PlayerBase::ImpulseCommands hook
using ReHookPlayerImpulseCommands = HookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerImpulseCommands = HookChainClassRegistry<void, PlayerBase>;

// PlayerBase::RoundRespawn hook
using ReHookPlayerRoundRespawn = HookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerRoundRespawn = HookChainClassRegistry<void, PlayerBase>;

// PlayerBase::Blind hook
using ReHookPlayerBaseBlind = HookChainClass<void, PlayerBase, float, float, float, int>;
using ReHookRegistryPlayerBaseBlind = HookChainClassRegistry<void, PlayerBase, float, float, float, int>;

// PlayerBase::Observer_IsValidTarget hook
using ReHookPlayerObserverIsValidTarget = HookChainClass<PlayerBase*, PlayerBase, int, bool>;
using ReHookRegistryPlayerObserverIsValidTarget = HookChainClassRegistry<PlayerBase*, PlayerBase, int, bool>;

// PlayerBase::SetAnimation hook
using ReHookPlayerSetAnimation = HookChainClass<void, PlayerBase, PlayerAnim>;
using ReHookRegistryPlayerSetAnimation = HookChainClassRegistry<void, PlayerBase, PlayerAnim>;

// PlayerBase::GiveDefaultItems hook
using ReHookPlayerGiveDefaultItems = HookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerGiveDefaultItems = HookChainClassRegistry<void, PlayerBase>;

// PlayerBase::GiveNamedItem hook
using ReHookPlayerGiveNamedItem = HookChainClass<EntityBase*, PlayerBase, const char*>;
using ReHookRegistryPlayerGiveNamedItem = HookChainClassRegistry<EntityBase*, PlayerBase, const char*>;

// PlayerBase::AddAccount hook
using ReHookPlayerAddAccount = HookChainClass<void, PlayerBase, int, RewardType, bool>;
using ReHookRegistryPlayerAddAccount = HookChainClassRegistry<void, PlayerBase, int, RewardType, bool>;

// PlayerBase::GiveShield hook
using ReHookPlayerGiveShield = HookChainClass<void, PlayerBase, bool>;
using ReHookRegistryPlayerGiveShield = HookChainClassRegistry<void, PlayerBase, bool>;

// PlayerBase:SetClientUserInfoModel hook
using ReHookPlayerSetClientUserInfoModel = HookChainClass<void, PlayerBase, char*, char*>;
using ReHookRegistryPlayerSetClientUserInfoModel = HookChainClassRegistry<void, PlayerBase, char*, char*>;

// PlayerBase:SetClientUserInfoName hook
using ReHookPlayerSetClientUserInfoName = HookChainClass<bool, PlayerBase, char*, char*>;
using ReHookRegistryPlayerSetClientUserInfoName = HookChainClassRegistry<bool, PlayerBase, char*, char*>;

// PlayerBase::HasRestrictItem hook
using ReHookPlayerHasRestrictItem = HookChainClass<bool, PlayerBase, ItemId, ItemRestType>;
using ReHookRegistryPlayerHasRestrictItem = HookChainClassRegistry<bool, PlayerBase, ItemId, ItemRestType>;

// PlayerBase::DropPlayerItem hook
using ReHookPlayerDropPlayerItem = HookChainClass<EntityBase*, PlayerBase, const char*>;
using ReHookRegistryPlayerDropPlayerItem = HookChainClassRegistry<EntityBase*, PlayerBase, const char*>;

// PlayerBase::DropShield hook
using ReHookPlayerDropShield = HookChainClass<EntityBase*, PlayerBase, bool>;
using ReHookRegistryPlayerDropShield = HookChainClassRegistry<EntityBase*, PlayerBase, bool>;

// PlayerBase::OnSpawnEquip hook
using ReHookPlayerOnSpawnEquip = HookChainClass<void, PlayerBase, bool, bool>;
using ReHookRegistryPlayerOnSpawnEquip = HookChainClassRegistry<void, PlayerBase, bool, bool>;

// PlayerBase::Radio hook
using ReHookPlayerRadio = HookChainClass<void, PlayerBase, const char*, const char*, short, bool>;
using ReHookRegistryPlayerRadio = HookChainClassRegistry<void, PlayerBase, const char*, const char*, short, bool>;

// PlayerBase::Disappear hook
using ReHookPlayerDisappear = HookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerDisappear = HookChainClassRegistry<void, PlayerBase>;

// PlayerBase::MakeVIP hook
using ReHookPlayerMakeVip = HookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerMakeVip = HookChainClassRegistry<void, PlayerBase>;

// PlayerBase::MakeBomber hook
using ReHookPlayerMakeBomber = HookChainClass<bool, PlayerBase>;
using ReHookRegistryPlayerMakeBomber = HookChainClassRegistry<bool, PlayerBase>;

// PlayerBase::StartObserver hook
using ReHookPlayerStartObserver = HookChainClass<void, PlayerBase, Vector&, Vector&>;
using ReHookRegistryPlayerStartObserver = HookChainClassRegistry<void, PlayerBase, Vector&, Vector&>;

// PlayerBase::GetIntoGame hook
using ReHookPlayerGetIntoGame = HookChainClass<bool, PlayerBase>;
using ReHookRegistryPlayerGetIntoGame = HookChainClassRegistry<bool, PlayerBase>;

// AnimatingBase::ResetSequenceInfo hook
using ReHookAnimatingResetSequenceInfo = HookChainClass<void, AnimatingBase>;
using ReHookRegistryAnimatingResetSequenceInfo = HookChainClassRegistry<void, AnimatingBase>;

// GetForceCamera hook
using ReHookGetForceCamera = HookChain<int, PlayerBase*>;
using ReHookRegistryGetForceCamera = HookChainRegistry<int, PlayerBase*>;

// PlayerBlind hook
using ReHookPlayerBlind = HookChain<void, PlayerBase*, EntityVars*, EntityVars*, float, float, int, Vector&>;
using ReHookRegistryPlayerBlind = HookChainRegistry<void, PlayerBase*, EntityVars*, EntityVars*, float, float, int, Vector&>;

// RadiusFlash_TraceLine hook
using ReHookRadiusFlashTraceLine = HookChain<void, PlayerBase*, EntityVars*, EntityVars*, Vector&, Vector&, TraceResult*>;
using ReHookRegistryRadiusFlashTraceLine = HookChainRegistry<void, PlayerBase*, EntityVars*, EntityVars*, Vector&, Vector&, TraceResult*>;

// RoundEnd hook
using ReHookRoundEnd = HookChain<bool, int, ScenarioEventEndRound, float>;
using ReHookRegistryRoundEnd = HookChainRegistry<bool, int, ScenarioEventEndRound, float>;

// InstallGameRules hook
using ReHookInstallGameRules = HookChain<GameRules*>;
using ReHookRegistryInstallGameRules = HookChainRegistry<GameRules*>;

// PM_Init hook
using ReHookPmInit = HookChain<void, PlayerMove*>;
using ReHookRegistryPmInit = HookChainRegistry<void, PlayerMove*>;

// PM_Move hook
using ReHookPmMove = HookChain<void, PlayerMove*, int>;
using ReHookRegistryPmMove = HookChainRegistry<void, PlayerMove*, int>;

// PM_AirMove hook
using ReHookPmAirMove = HookChain<void, int>;
using ReHookRegistryPmAirMove = HookChainRegistry<void, int>;

// HandleMenu_ChooseAppearance hook
using ReHookHandleMenuChooseAppearance = HookChain<void, PlayerBase*, int>;
using ReHookRegistryHandleMenuChooseAppearance = HookChainRegistry<void, PlayerBase*, int>;

// HandleMenu_ChooseTeam hook
using ReHookHandleMenuChooseTeam = HookChain<qboolean, PlayerBase*, int>;
using ReHookRegistryHandleMenuChooseTeam = HookChainRegistry<qboolean, PlayerBase*, int>;

// ShowMenu hook
using ReHookShowMenu = HookChain<void, PlayerBase*, int, int, qboolean, char*>;
using ReHookRegistryShowMenu = HookChainRegistry<void, PlayerBase*, int, int, qboolean, char*>;

// ShowVGUIMenu hook
using ReHookShowVguiMenu = HookChain<void, PlayerBase*, int, int, char*>;
using ReHookRegistryShowVguiMenu = HookChainRegistry<void, PlayerBase*, int, int, char*>;

// BuyGunAmmo hook
using ReHookBuyGunAmmo = HookChain<bool, PlayerBase*, PlayerItemBase*, bool>;
using ReHookRegistryBuyGunAmmo = HookChainRegistry<bool, PlayerBase*, PlayerItemBase*, bool>;

// BuyWeaponByWeaponID hook
using ReHookBuyWeaponByWeaponId = HookChain<EntityBase*, PlayerBase*, WeaponId>;
using ReHookRegistryBuyWeaponByWeaponId = HookChainRegistry<EntityBase*, PlayerBase*, WeaponId>;

// InternalCommand hook
using ReHookInternalCommand = HookChain<void, Edict*, const char*, const char*>;
using ReHookRegistryInternalCommand = HookChainRegistry<void, Edict*, const char*, const char*>;

// CHalfLifeMultiplay::FShouldSwitchWeapon hook
using ReHookGameRulesShouldSwitchWeapon = HookChain<qboolean, PlayerBase*, PlayerItemBase*>;
using ReHookRegistryGameRulesShouldSwitchWeapon = HookChainRegistry<qboolean, PlayerBase*, PlayerItemBase*>;

// CHalfLifeMultiplay::GetNextBestWeapon hook
using ReHookGameRulesGetNextBestWeapon = HookChain<qboolean, PlayerBase*, PlayerItemBase*>;
using ReHookRegistryGameRulesGetNextBestWeapon = HookChainRegistry<qboolean, PlayerBase*, PlayerItemBase*>;

// CHalfLifeMultiplay::FlPlayerFallDamage hook
using ReHookGameRulesPlayerFallDamage = HookChain<float, PlayerBase*>;
using ReHookRegistryGameRulesPlayerFallDamage = HookChainRegistry<float, PlayerBase*>;

// CHalfLifeMultiplay::FPlayerCanTakeDamage hook
using ReHookGameRulesPlayerCanTakeDamage = HookChain<qboolean, PlayerBase*, EntityBase*>;
using ReHookRegistryGameRulesPlayerCanTakeDamage = HookChainRegistry<qboolean, PlayerBase*, EntityBase*>;

// CHalfLifeMultiplay::PlayerSpawn hook
using ReHookGameRulesPlayerSpawn = HookChain<void, PlayerBase*>;
using ReHookRegistryGameRulesPlayerSpawn = HookChainRegistry<void, PlayerBase*>;

// CHalfLifeMultiplay::FPlayerCanRespawn hook
using ReHookGameRulesPlayerCanRespawn = HookChain<qboolean, PlayerBase*>;
using ReHookRegistryGameRulesPlayerCanRespawn = HookChainRegistry<qboolean, PlayerBase*>;

// CHalfLifeMultiplay::GetPlayerSpawnSpot hook
using ReHookGameRulesGetPlayerSpawnSpot = HookChain<Edict*, PlayerBase*>;
using ReHookRegistryGameRulesGetPlayerSpawnSpot = HookChainRegistry<Edict*, PlayerBase*>;

// CHalfLifeMultiplay::ClientUserInfoChanged hook
using ReHookGameRulesClientUserInfoChanged = HookChain<void, PlayerBase*, char*>;
using ReHookRegistryGameRulesClientUserInfoChanged = HookChainRegistry<void, PlayerBase*, char*>;

// CHalfLifeMultiplay::PlayerKilled hook
using ReHookGameRulesPlayerKilled = HookChain<void, PlayerBase*, EntityVars*, EntityVars*>;
using ReHookRegistryGameRulesPlayerKilled = HookChainRegistry<void, PlayerBase*, EntityVars*, EntityVars*>;

// CHalfLifeMultiplay::DeathNotice hook
using ReHookGameRulesDeathNotice = HookChain<void, PlayerBase*, EntityVars*, EntityVars*>;
using ReHookRegistryGameRulesDeathNotice = HookChainRegistry<void, PlayerBase*, EntityVars*, EntityVars*>;

// CHalfLifeMultiplay::CanHavePlayerItem hook
using ReHookGameRulesCanHavePlayerItem = HookChain<qboolean, PlayerBase*, PlayerItemBase*>;
using ReHookRegistryGameRulesCanHavePlayerItem = HookChainRegistry<qboolean, PlayerBase*, PlayerItemBase*>;

// CHalfLifeMultiplay::DeadPlayerWeapons hook
using ReHookGameRulesDeadPlayerWeapons = HookChain<int, PlayerBase*>;
using ReHookRegistryGameRulesDeadPlayerWeapons = HookChainRegistry<int, PlayerBase*>;

// CHalfLifeMultiplay::ServerDeactivate hook
using ReHookGameRulesServerDeactivate = HookChain<void>;
using ReHookRegistryGameRulesServerDeactivate = HookChainRegistry<void>;

// CHalfLifeMultiplay::CheckMapConditions hook
using ReHookGameRulesCheckMapConditions = HookChain<void>;
using ReHookRegistryGameRulesCheckMapConditions = HookChainRegistry<void>;

// CHalfLifeMultiplay::CleanUpMap hook
using ReHookGameRulesCleanUpMap = HookChain<void>;
using ReHookRegistryGameRulesCleanUpMap = HookChainRegistry<void>;

// CHalfLifeMultiplay::RestartRound hook
using ReHookGameRulesRestartRound = HookChain<void>;
using ReHookRegistryGameRulesRestartRound = HookChainRegistry<void>;

// CHalfLifeMultiplay::CheckWinConditions hook
using ReHookGameRulesCheckWinConditions = HookChain<void>;
using ReHookRegistryGameRulesCheckWinConditions = HookChainRegistry<void>;

// CHalfLifeMultiplay::RemoveGuns hook
using ReHookGameRulesRemoveGuns = HookChain<void>;
using ReHookRegistryGameRulesRemoveGuns = HookChainRegistry<void>;

// CHalfLifeMultiplay::GiveC4 hook
using ReHookGameRulesGiveC4 = HookChain<void>;
using ReHookRegistryGameRulesGiveC4 = HookChainRegistry<void>;

// CHalfLifeMultiplay::ChangeLevel hook
using ReHookGameRulesChangeLevel = HookChain<void>;
using ReHookRegistryGameRulesChangeLevel = HookChainRegistry<void>;

// CHalfLifeMultiplay::GoToIntermission hook
using ReHookGameRulesGoToIntermission = HookChain<void>;
using ReHookRegistryGameRulesGoToIntermission = HookChainRegistry<void>;

// CHalfLifeMultiplay::BalanceTeams hook
using ReHookGameRulesBalanceTeams = HookChain<void>;
using ReHookRegistryGameRulesBalanceTeams = HookChainRegistry<void>;

// CHalfLifeMultiplay::OnRoundFreezeEnd hook
using ReHookGameRulesOnRoundFreezeEnd = HookChain<void>;
using ReHookRegistryGameRulesOnRoundFreezeEnd = HookChainRegistry<void>;

// GameRules::CanPlayerHearPlayer hook
using ReHookGameRulesCanPlayerHearPlayer = HookChain<bool, PlayerBase*, PlayerBase*>;
using ReHookRegistryGameRulesCanPlayerHearPlayer = HookChainRegistry<bool, PlayerBase*, PlayerBase*>;

// PM_UpdateStepSound hook
using ReHookPmUpdateStepSound = HookChain<void>;
using ReHookRegistryPmUpdateStepSound = HookChainRegistry<void>;

// PlayerBase::StartDeathCam hook
using ReHookPlayerStartDeathCam = HookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerStartDeathCam = HookChainClassRegistry<void, PlayerBase>;

// PlayerBase::SwitchTeam hook
using ReHookPlayerSwitchTeam = HookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerSwitchTeam = HookChainClassRegistry<void, PlayerBase>;

// PlayerBase::CanSwitchTeam hook
using ReHookPlayerCanSwitchTeam = HookChainClass<bool, PlayerBase, TeamName>;
using ReHookRegistryPlayerCanSwitchTeam = HookChainClassRegistry<bool, PlayerBase, TeamName>;

// PlayerBase::ThrowGrenade hook
using ReHookPlayerThrowGrenade = HookChainClass<Grenade*, PlayerBase, PlayerWeaponBase*, Vector&, Vector&, float, unsigned short>;
using ReHookRegistryPlayerThrowGrenade = HookChainClassRegistry<Grenade*, PlayerBase, PlayerWeaponBase*, Vector&, Vector&, float, unsigned short>;

// WeaponBox::SetModel hook
using ReHookWeaponBoxSetModel = HookChainClass<void, WeaponBox, const char*>;
using ReHookRegistryWeaponBoxSetModel = HookChainClassRegistry<void, WeaponBox, const char*>;

// Grenade::DefuseBombStart hook
using ReHookGrenadeDefuseBombStart = HookChainClass<void, Grenade, PlayerBase*>;
using ReHookRegistryGrenadeDefuseBombStart = HookChainClassRegistry<void, Grenade, PlayerBase*>;

// Grenade::DefuseBombEnd hook
using ReHookGrenadeDefuseBombEnd = HookChainClass<void, Grenade, PlayerBase*, bool>;
using ReHookRegistryGrenadeDefuseBombEnd = HookChainClassRegistry<void, Grenade, PlayerBase*, bool>;

// Grenade::ExplodeHeGrenade hook
using ReHookGrenadeExplodeHeGrenade = HookChainClass<void, Grenade, TraceResult*, int>;
using ReHookRegistryGrenadeExplodeHeGrenade = HookChainClassRegistry<void, Grenade, TraceResult*, int>;

// Grenade::Explodeflash_bang hook
using ReHookGrenadeExplodeFlashBang = HookChainClass<void, Grenade, TraceResult*, int>;
using ReHookRegistryGrenadeExplodeFlashBang = HookChainClassRegistry<void, Grenade, TraceResult*, int>;

// Grenade::ExplodeSmokeGrenade hook
using ReHookGrenadeExplodeSmokeGrenade = HookChainClass<void, Grenade>;
using ReHookRegistryGrenadeExplodeSmokeGrenade = HookChainClassRegistry<void, Grenade>;

// Grenade::ExplodeBomb hook
using ReHookGrenadeExplodeBomb = HookChainClass<void, Grenade, TraceResult*, int>;
using ReHookRegistryGrenadeExplodeBomb = HookChainClassRegistry<void, Grenade, TraceResult*, int>;

// ThrowHeGrenade hook
using ReHookThrowHeGrenade = HookChain<Grenade*, EntityVars*, Vector&, Vector&, float, int, unsigned short>;
using ReHookRegistryThrowHeGrenade = HookChainRegistry<Grenade*, EntityVars*, Vector&, Vector&, float, int, unsigned short>;

// Throw_flash_bang hook
using ReHookThrowFlashBang = HookChain<Grenade*, EntityVars*, Vector&, Vector&, float>;
using ReHookRegistryThrowFlashBang = HookChainRegistry<Grenade*, EntityVars*, Vector&, Vector&, float>;

// ThrowSmokeGrenade hook
using ReHookThrowSmokeGrenade = HookChain<Grenade*, EntityVars*, Vector&, Vector&, float, unsigned short>;
using ReHookRegistryThrowSmokeGrenade = HookChainRegistry<Grenade*, EntityVars*, Vector&, Vector&, float, unsigned short>;

// PlantBomb hook
using ReHookPlantBomb = HookChain<Grenade*, EntityVars*, Vector&, Vector&>;
using ReHookRegistryPlantBomb = HookChainRegistry<Grenade*, EntityVars*, Vector&, Vector&>;

// PlayerBase::SetSpawnProtection hook
using ReHookPlayerSetSpawnProtection = HookChainClass<void, PlayerBase, float>;
using ReHookRegistryPlayerSetSpawnProtection = HookChainClassRegistry<void, PlayerBase, float>;

// PlayerBase::RemoveSpawnProtection hook
using ReHookPlayerRemoveSpawnProtection = HookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerRemoveSpawnProtection = HookChainClassRegistry<void, PlayerBase>;

// IsPenetrableEntity hook
using ReHookIsPenetrableEntity = HookChain<bool, Vector&, Vector&, EntityVars*, Edict*>;
using ReHookRegistryIsPenetrableEntity = HookChainRegistry<bool, Vector&, Vector&, EntityVars*, Edict*>;

// PlayerBase::HintMessageEx hook
using ReHookPlayerHintMessageEx = HookChainClass<bool, PlayerBase, const char*, float, bool, bool>;
using ReHookRegistryPlayerHintMessageEx = HookChainClassRegistry<bool, PlayerBase, const char*, float, bool, bool>;

// PlayerBase::UseEmpty hook
using ReHookPlayerUseEmpty = HookChainClass<void, PlayerBase>;
using ReHookRegistryPlayerUseEmpty = HookChainClassRegistry<void, PlayerBase>;

// player_baseWeapon::CanDeploy hook
using ReHookPlayerWeaponCanDeploy = HookChainClass<qboolean, PlayerWeaponBase>;
using ReHookRegistryPlayerWeaponCanDeploy = HookChainClassRegistry<qboolean, PlayerWeaponBase>;

// player_baseWeapon::DefaultDeploy hook
using ReHookPlayerWeaponDefaultDeploy = HookChainClass<qboolean, PlayerWeaponBase, char*, char*, int, char*, int>;
using ReHookRegistryPlayerWeaponDefaultDeploy = HookChainClassRegistry<qboolean, PlayerWeaponBase, char*, char*, int, char*, int>;

// player_baseWeapon::DefaultReload hook
using ReHookPlayerWeaponDefaultReload = HookChainClass<int, PlayerWeaponBase, int, int, float>;
using ReHookRegistryPlayerWeaponDefaultReload = HookChainClassRegistry<int, PlayerWeaponBase, int, int, float>;

// player_baseWeapon::DefaultShotgunReload hook
using ReHookPlayerWeaponDefaultShotgunReload = HookChainClass<bool, PlayerWeaponBase, int, int, float, float, const char*, const char*>;
using ReHookRegistryPlayerWeaponDefaultShotgunReload = HookChainClassRegistry<bool, PlayerWeaponBase, int, int, float, float, const char*, const char*>;

// PlayerBase::DropIdlePlayer hook
using ReHookPlayerDropIdlePlayer = HookChainClass<void, PlayerBase, const char*>;
using ReHookRegistryPlayerDropIdlePlayer = HookChainClassRegistry<void, PlayerBase, const char*>;

// CreateWeaponBox hook
using ReHookCreateWeaponBox = HookChain<WeaponBox*, PlayerItemBase*, PlayerBase*, const char*, Vector&, Vector&, Vector&, float, bool>;
using ReHookRegistryCreateWeaponBox = HookChainRegistry<WeaponBox*, PlayerItemBase*, PlayerBase*, const char*, Vector&, Vector&, Vector&, float, bool>;

/// <summary>
/// Class RegamedllHookChains.
/// </summary>
class RegamedllHookChains {
public:
	/// <summary>
	/// </summary>
	virtual ~RegamedllHookChains() = default;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerSpawn* player_spawn() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerPrecache* player_precache() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerObjectCaps* player_object_caps() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerClassify* player_classify() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerTraceAttack* player_trace_attack() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerTakeDamage* player_take_damage() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerTakeHealth* player_take_health() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerKilled* player_killed() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerAddPoints* player_add_points() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerAddPointsToTeam* player_add_points_to_team() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerAddPlayerItem* player_add_player_item() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerRemovePlayerItem* player_remove_player_item() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerGiveAmmo* player_give_ammo() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerResetMaxSpeed* player_reset_max_speed() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerJump* player_jump() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerDuck* player_duck() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerPreThink* player_pre_think() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerPostThink* player_post_think() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerUpdateClientData* player_update_client_data() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerImpulseCommands* player_impulse_commands() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerRoundRespawn* player_round_respawn() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerBaseBlind* player_base_blind() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerObserverIsValidTarget* player_observer_is_valid_target() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerSetAnimation* player_set_animation() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerGiveDefaultItems* player_give_default_items() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerGiveNamedItem* player_give_named_item() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerAddAccount* player_add_account() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerGiveShield* player_give_shield() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerSetClientUserInfoModel* player_set_client_user_info_model() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerSetClientUserInfoName* player_set_client_user_info_name() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerHasRestrictItem* player_has_restrict_item() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerDropPlayerItem* player_drop_player_item() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerDropShield* player_drop_shield() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerOnSpawnEquip* player_on_spawn_equip() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerRadio* player_radio() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerDisappear* player_disappear() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerMakeVip* player_make_vip() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerMakeBomber* player_make_bomber() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerStartObserver* player_start_observer() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerGetIntoGame* player_get_into_game() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryAnimatingResetSequenceInfo* animating_reset_sequence_info() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGetForceCamera* get_force_camera() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerBlind* player_blind() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryRadiusFlashTraceLine* radius_flash_trace_line() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryRoundEnd* round_end() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryInstallGameRules* install_game_rules() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPmInit* pm_init() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPmMove* pm_move() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPmAirMove* pm_air_move() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryHandleMenuChooseAppearance* handle_menu_choose_appearance() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryHandleMenuChooseTeam* handle_menu_choose_team() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryShowMenu* show_menu() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryShowVguiMenu* show_vgui_menu() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryBuyGunAmmo* buy_gun_ammo() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryBuyWeaponByWeaponId* buy_weapon_by_weapon_id() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryInternalCommand* internal_command() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesShouldSwitchWeapon* game_rules_should_switch_weapon() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesGetNextBestWeapon* game_rules_get_next_best_weapon() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesPlayerFallDamage* game_rules_player_fall_damage() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesPlayerCanTakeDamage* game_rules_player_can_take_damage() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesPlayerSpawn* game_rules_player_spawn() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesPlayerCanRespawn* game_rules_player_can_respawn() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesGetPlayerSpawnSpot* game_rules_get_player_spawn_spot() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesClientUserInfoChanged* game_rules_client_user_info_changed() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesPlayerKilled* game_rules_player_killed() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesDeathNotice* game_rules_death_notice() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesCanHavePlayerItem* game_rules_can_have_player_item() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesDeadPlayerWeapons* game_rules_dead_player_weapons() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesServerDeactivate* game_rules_server_deactivate() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesCheckMapConditions* game_rules_check_map_conditions() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesCleanUpMap* game_rules_clean_up_map() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesRestartRound* game_rules_restart_round() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesCheckWinConditions* game_rules_check_win_conditions() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesRemoveGuns* game_rules_remove_guns() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesGiveC4* game_rules_give_c4() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesChangeLevel* game_rules_change_level() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesGoToIntermission* game_rules_go_to_intermission() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesBalanceTeams* game_rules_balance_teams() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesOnRoundFreezeEnd* game_rules_on_round_freeze_end() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPmUpdateStepSound* pm_update_step_sound() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerStartDeathCam* player_start_death_cam() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerSwitchTeam* player_switch_team() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerCanSwitchTeam* player_can_switch_team() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerThrowGrenade* player_throw_grenade() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGameRulesCanPlayerHearPlayer* game_rules_can_player_hear_player() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryWeaponBoxSetModel* weapon_box_set_model() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGrenadeDefuseBombStart* grenade_defuse_bomb_start() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGrenadeDefuseBombEnd* grenade_defuse_bomb_end() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGrenadeExplodeHeGrenade* grenade_explode_he_grenade() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGrenadeExplodeFlashBang* grenade_explode_flash_bang() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGrenadeExplodeSmokeGrenade* grenade_explode_smoke_grenade() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryGrenadeExplodeBomb* grenade_explode_bomb() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryThrowHeGrenade* throw_he_grenade() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryThrowFlashBang* throw_flash_bang() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryThrowSmokeGrenade* throw_smoke_grenade() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlantBomb* plant_bomb() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerRemoveSpawnProtection* player_remove_spawn_protection() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerSetSpawnProtection* player_set_spawn_protection() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryIsPenetrableEntity* is_penetrable_entity() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerHintMessageEx* player_hint_message_ex() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerUseEmpty* player_use_empty() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerWeaponCanDeploy* player_base_weapon_can_deploy() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerWeaponDefaultDeploy* player_base_weapon_default_deploy() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerWeaponDefaultReload* player_base_weapon_default_reload() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerWeaponDefaultShotgunReload* player_base_weapon_default_shotgun_reload() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryPlayerDropIdlePlayer* player_drop_idle_player() = 0;

	/// <summary>
	/// </summary>
	virtual ReHookRegistryCreateWeaponBox* create_weapon_box() = 0;
};

/// <summary>
/// </summary>
struct RegamedllFuncs {
	/// <summary>
	/// </summary>
	Edict* (*create_named_entity2)(Strind class_name){};

	/// <summary>
	/// </summary>
	void (*change_string)(char*& dest, const char* source){};

	/// <summary>
	/// </summary>
	void (*radius_damage)(Vector src, EntityVars* inflictor, EntityVars* attacker, float damage, float radius, int class_ignore, int damage_type){};

	/// <summary>
	/// </summary>
	void (*clear_multi_damage)(){};

	/// <summary>
	/// </summary>
	void (*apply_multi_damage)(EntityVars* inflictor, EntityVars* attacker){};

	/// <summary>
	/// </summary>
	void (*add_multi_damage)(EntityVars* inflictor, EntityBase* entity, float damage, int damage_type){};

	/// <summary>
	/// </summary>
	EntityBase* (*find_entity_by_string)(EntityBase* start_entity, const char* keyword, const char* value){};

	/// <summary>
	/// </summary>
	void (*add_entity_hash_value)(EntityVars* ent_vars, const char* value, HashType field_type){};

	/// <summary>
	/// </summary>
	void (*remove_entity_hash_value)(EntityVars* ent_vars, const char* value, HashType field_type){};

	/// <summary>
	/// </summary>
	int (*cmd_argc)(){};

	/// <summary>
	/// </summary>
	const char* (*cmd_argv)(int i){};
};

/// <summary>
/// Class RegamedllApiInterface.
/// </summary>
class RegamedllApiInterface {
public:
	/// <summary>
	/// </summary>
	virtual ~RegamedllApiInterface() = default;

	/// <summary>
	/// </summary>
	virtual int get_major_version() = 0;

	/// <summary>
	/// </summary>
	virtual int get_minor_version() = 0;

	/// <summary>
	/// </summary>
	virtual const RegamedllFuncs* get_funcs() = 0;

	/// <summary>
	/// </summary>
	virtual RegamedllHookChains* get_hook_chains() = 0;

	/// <summary>
	/// </summary>
	virtual GameRules* get_game_rules() = 0;

	/// <summary>
	/// </summary>
	virtual WeaponInfoStruct* get_weapon_info(WeaponId weapon) = 0;

	/// <summary>
	/// </summary>
	virtual WeaponInfoStruct* get_weapon_info(const char* weapon) = 0;

	/// <summary>
	/// </summary>
	virtual PlayerMove* get_player_move() = 0;

	/// <summary>
	/// </summary>
	virtual WeaponSlotInfo* get_weapon_slot(WeaponId weapon) = 0;

	/// <summary>
	/// </summary>
	virtual WeaponSlotInfo* get_weapon_slot(const char* weapon) = 0;

	/// <summary>
	/// </summary>
	virtual ItemInfo* get_item_info(WeaponId weapon) = 0;

	/// <summary>
	/// </summary>
	virtual AmmoInfo* get_ammo_info(AmmoType ammo) = 0;

	/// <summary>
	/// </summary>
	virtual AmmoInfoStruct* get_ammo_info_ex(AmmoType ammo) = 0;

	/// <summary>
	/// </summary>
	virtual AmmoInfoStruct* get_ammo_info_ex(const char* ammo) = 0;

	/// <summary>
	/// </summary>
	virtual bool check_cs_entity_version(const char* version) const = 0;

	/// <summary>
	/// </summary>
	virtual bool check_game_rules_version(const char* version) const = 0;
};
