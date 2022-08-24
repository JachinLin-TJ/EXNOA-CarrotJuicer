#pragma once
typedef int32_t ImageIndex;
typedef int32_t CustomAttributeIndex;
typedef int32_t StringIndex;
typedef struct Il2CppAssemblyName
{
    StringIndex nameIndex;
    StringIndex cultureIndex;
    StringIndex hashValueIndex;
    StringIndex publicKeyIndex;
    uint32_t hash_alg;
    int32_t hash_len;
    uint32_t flags;
    int32_t major;
    int32_t minor;
    int32_t build;
    int32_t revision;
    uint8_t publicKeyToken[8];
} Il2CppAssemblyName;
typedef struct Il2CppAssembly
{
    ImageIndex imageIndex;
    CustomAttributeIndex customAttributeIndex;
    int32_t referencedAssemblyStart;
    int32_t referencedAssemblyCount;
    Il2CppAssemblyName aname;
} Il2CppAssembly;


struct Gallop_PresentListBase_FilterCategory_array {
	Il2CppObject obj;
	Il2CppArrayBounds* bounds;
	il2cpp_array_size_t max_length;
	int32_t m_Items[65535];
};


struct System_Reflection_MethodImplAttributes_Fields {
	int32_t value__;
};

struct System_Reflection_MethodImplAttributes_o {
	System_Reflection_MethodImplAttributes_Fields fields;
};

struct __declspec(align(8)) System_Reflection_MemberInfo_Fields {
};

struct System_Reflection_MethodBase_Fields : System_Reflection_MemberInfo_Fields {
};

struct System_Reflection_MethodInfo_Fields : System_Reflection_MethodBase_Fields {
};



struct __declspec(align(8)) System_Delegate_Fields {
	intptr_t method_ptr;
	intptr_t invoke_impl;
	Il2CppObject* m_target;
	intptr_t method;
	intptr_t delegate_trampoline;
	intptr_t extra_arg;
	intptr_t method_code;
	struct System_Reflection_MethodInfo_o* method_info;
	struct System_Reflection_MethodInfo_o* original_method_info;
	struct System_DelegateData_o* data;
	bool method_is_virtual;
};
struct System_MulticastDelegate_Fields : System_Delegate_Fields {
	struct System_Delegate_array* delegates;
};
struct System_Action_PresentData____Fields : System_MulticastDelegate_Fields {
};


struct Il2CppClass_1
{
	void* image;
	void* gc_desc;
	const char* name;
	const char* namespaze;
	Il2CppType byval_arg;
	Il2CppType this_arg;
	Il2CppClass* element_class;
	Il2CppClass* castClass;
	Il2CppClass* declaringType;
	Il2CppClass* parent;
	void* generic_class;
	void* typeMetadataHandle;
	void* interopData;
	Il2CppClass* klass;
	void* fields;
	void* events;
	void* properties;
	void* methods;
	Il2CppClass** nestedTypes;
	Il2CppClass** implementedInterfaces;
	Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
};

struct Il2CppClass_2
{
	Il2CppClass** typeHierarchy;
	void* unity_user_data;
	uint32_t initializationExceptionGCHandle;
	uint32_t cctor_started;
	uint32_t cctor_finished;
	size_t cctor_thread;
	void* genericContainerHandle;
	uint32_t instance_size;
	uint32_t actualSize;
	uint32_t element_size;
	int32_t native_size;
	uint32_t static_fields_size;
	uint32_t thread_static_fields_size;
	int32_t thread_static_fields_offset;
	uint32_t flags;
	uint32_t token;
	uint16_t method_count;
	uint16_t property_count;
	uint16_t field_count;
	uint16_t event_count;
	uint16_t nested_type_count;
	uint16_t vtable_count;
	uint16_t interfaces_count;
	uint16_t interface_offsets_count;
	uint8_t typeHierarchyDepth;
	uint8_t genericRecursionDepth;
	uint8_t rank;
	uint8_t minimumAlignment;
	uint8_t naturalAligment;
	uint8_t packingSize;
	uint8_t bitflags1;
	uint8_t bitflags2;
};


struct System_Action_PresentData____VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_unknown;
	VirtualInvokeData _6_DynamicInvokeImpl;
	VirtualInvokeData _7_Clone;
	VirtualInvokeData _8_GetMethodImpl;
	VirtualInvokeData _9_GetObjectData;
	VirtualInvokeData _10_GetInvocationList;
	VirtualInvokeData _11_CombineImpl;
	VirtualInvokeData _12_RemoveImpl;
	VirtualInvokeData _13_Invoke;
	VirtualInvokeData _14_BeginInvoke;
	VirtualInvokeData _15_EndInvoke;
};
struct System_Action_PresentData____c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Action_PresentData____VTable vtable;
};
struct System_Action_PresentData____o {
	System_Action_PresentData____c* klass;
	void* monitor;
	System_Action_PresentData____Fields fields;
};
struct Gallop_PartsPresentListItemBase_Info_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct Gallop_PartsPresentListItemBase_Info_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_PartsPresentListItemBase_Info_VTable vtable;
};
struct __declspec(align(8)) Gallop_PartsPresentListItemBase_Info_Fields {
	int32_t _Category_k__BackingField;
	int32_t _PresentId_k__BackingField;
	int32_t _RewardId_k__BackingField;
	int32_t _Num_k__BackingField;
	int64_t _LimitTimeStamp_k__BackingField;
	struct System_String_o* _Name_k__BackingField;
	struct System_String_o* _LimitText_k__BackingField;
	bool _IsLimitOver_k__BackingField;
	bool _IsLimitMoment_k__BackingField;
	struct System_String_o* _Message_k__BackingField;
	struct System_String_o* _CreateDate_k__BackingField;
	struct System_String_o* _ReceiveDate_k__BackingField;
};
struct Gallop_PartsPresentListItemBase_Info_o {
	Gallop_PartsPresentListItemBase_Info_c* klass;
	void* monitor;
	Gallop_PartsPresentListItemBase_Info_Fields fields;
};
struct Cute_Http_IWebRequest_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	VirtualInvokeData vtable[32];
}; 
struct __declspec(align(8)) Cute_Http_IWebRequest_Fields {
};
struct Cute_Http_IWebRequest_o {
	Cute_Http_IWebRequest_c* klass;
	void* monitor;
	Cute_Http_IWebRequest_Fields fields;
};



struct __declspec(align(8)) UnityEngine_Object_Fields {
	intptr_t m_CachedPtr;
};

struct UnityEngine_Component_Fields : UnityEngine_Object_Fields {
};

struct UnityEngine_Behaviour_Fields : UnityEngine_Component_Fields {
};

struct UnityEngine_MonoBehaviour_Fields : UnityEngine_Behaviour_Fields {
};

struct Gallop_PresentListBase_Fields : UnityEngine_MonoBehaviour_Fields {
	struct Gallop_ScrollRectCommon_o* _scrollRect;
	struct Gallop_LoopScroll_o* _loopScroll;
	struct Gallop_FlickableObject_o* _flick;
	struct UnityEngine_GameObject_o* _emptyObj;
	struct System_Collections_Generic_List_PartsPresentListItemBase_Info__o* _infoList;
	struct Gallop_PartsPresentListItemBase_array* _childCacheArray;
	bool _appendConnecting;
	bool _isLast;
	struct Gallop_DialogPresent_o* _dialogPresent;
	bool _isTimeAsc;
	int32_t _limit;
	struct Gallop_PresentListBase_FilterCategory_array* _categoryArray;
	struct Gallop_PresentData_array* _responsePresentDataArray;
	bool _IsInitialized_k__BackingField;
};
struct Gallop_PresentListBase_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Initialize;
	VirtualInvokeData _5_Initialize;
	VirtualInvokeData _6_APIIndex;
	VirtualInvokeData _7_CheckIsLast;
	VirtualInvokeData _8_Receive;
};
struct Gallop_PresentListBase_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_PresentListBase_VTable vtable;
};
struct Gallop_PresentListBase_o {
	Gallop_PresentListBase_c* klass;
	void* monitor;
	Gallop_PresentListBase_Fields fields;
};

struct Gallop_PartsPresentListItemBase_Info_array {
	Il2CppObject obj;
	Il2CppArrayBounds* bounds;
	il2cpp_array_size_t max_length;
	Gallop_PartsPresentListItemBase_Info_o* m_Items[65535];
};

struct __declspec(align(8)) System_Collections_Generic_List_PartsPresentListItemBase_Info__Fields {
	struct Gallop_PartsPresentListItemBase_Info_array* _items;
	int32_t _size;
	int32_t _version;
	Il2CppObject* _syncRoot;
};
struct System_Collections_Generic_List_PartsPresentListItemBase_Info__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_set_Item;
	VirtualInvokeData _6_IndexOf;
	VirtualInvokeData _7_Insert;
	VirtualInvokeData _8_unknown;
	VirtualInvokeData _9_unknown;
	VirtualInvokeData _10_System_Collections_Generic_ICollection_T__get_IsReadOnly;
	VirtualInvokeData _11_Add;
	VirtualInvokeData _12_unknown;
	VirtualInvokeData _13_Contains;
	VirtualInvokeData _14_CopyTo;
	VirtualInvokeData _15_Remove;
	VirtualInvokeData _16_System_Collections_Generic_IEnumerable_T__GetEnumerator;
	VirtualInvokeData _17_System_Collections_IEnumerable_GetEnumerator;
	VirtualInvokeData _18_System_Collections_IList_get_Item;
	VirtualInvokeData _19_System_Collections_IList_set_Item;
	VirtualInvokeData _20_System_Collections_IList_Add;
	VirtualInvokeData _21_System_Collections_IList_Contains;
	VirtualInvokeData _22_Clear;
	VirtualInvokeData _23_System_Collections_IList_get_IsReadOnly;
	VirtualInvokeData _24_System_Collections_IList_get_IsFixedSize;
	VirtualInvokeData _25_System_Collections_IList_IndexOf;
	VirtualInvokeData _26_System_Collections_IList_Insert;
	VirtualInvokeData _27_System_Collections_IList_Remove;
	VirtualInvokeData _28_RemoveAt;
	VirtualInvokeData _29_System_Collections_ICollection_CopyTo;
	VirtualInvokeData _30_unknown;
	VirtualInvokeData _31_System_Collections_ICollection_get_SyncRoot;
	VirtualInvokeData _32_System_Collections_ICollection_get_IsSynchronized;
	VirtualInvokeData _33_get_Item;
	VirtualInvokeData _34_get_Count;
};
struct System_Collections_Generic_List_PartsPresentListItemBase_Info__c {
	Il2CppClass_1 _1;
	struct System_Collections_Generic_List_PartsPresentListItemBase_Info__StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Collections_Generic_List_PartsPresentListItemBase_Info__VTable vtable;
};

struct System_Collections_Generic_List_PartsPresentListItemBase_Info__o {
	System_Collections_Generic_List_PartsPresentListItemBase_Info__c* klass;
	void* monitor;
	System_Collections_Generic_List_PartsPresentListItemBase_Info__Fields fields;
};

struct System_Action_NoReceivePresentNum__Fields : System_MulticastDelegate_Fields {
};
struct System_Action_NoReceivePresentNum__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_unknown;
	VirtualInvokeData _6_DynamicInvokeImpl;
	VirtualInvokeData _7_Clone;
	VirtualInvokeData _8_GetMethodImpl;
	VirtualInvokeData _9_GetObjectData;
	VirtualInvokeData _10_GetInvocationList;
	VirtualInvokeData _11_CombineImpl;
	VirtualInvokeData _12_RemoveImpl;
	VirtualInvokeData _13_Invoke;
	VirtualInvokeData _14_BeginInvoke;
	VirtualInvokeData _15_EndInvoke;
};
struct System_Action_NoReceivePresentNum__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Action_NoReceivePresentNum__VTable vtable;
};
struct System_Action_NoReceivePresentNum__o {
	System_Action_NoReceivePresentNum__c* klass;
	void* monitor;
	System_Action_NoReceivePresentNum__Fields fields;
};

struct Gallop_PresentList_Fields : Gallop_PresentListBase_Fields {
	struct System_Collections_Generic_List_PartsPresentListItemBase_Info__o* _confirmPresentList;
	struct System_Action_NoReceivePresentNum__o* _updateNoRecieveNum;
};
struct Gallop_PresentList_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Initialize;
	VirtualInvokeData _5_Initialize;
	VirtualInvokeData _6_APIIndex;
	VirtualInvokeData _7_CheckIsLast;
	VirtualInvokeData _8_Receive;
};
struct Gallop_PresentList_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_PresentList_VTable vtable;
};

struct Gallop_PresentList_o {
	Gallop_PresentList_c* klass;
	void* monitor;
	Gallop_PresentList_Fields fields;
};

struct Gallop_DataHeader_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct Gallop_DataHeader_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_DataHeader_VTable vtable;
};

struct __declspec(align(8)) Gallop_DataHeader_Fields {
	int64_t viewer_id;
	struct System_String_o* sid;
	int64_t servertime;
	int32_t result_code;
	struct System_String_o* error_message;
	struct Gallop_NotificationInfo_o* notifications;
	struct Gallop_ServerList_o* server_list;
	struct System_String_o* store_url;
	struct System_String_o* service_preparation_message;
	struct System_String_o* resource_version;
	struct System_String_o* nonce;
};

struct Gallop_DataHeader_o {
	Gallop_DataHeader_c* klass;
	void* monitor;
	Gallop_DataHeader_Fields fields;
};
struct __declspec(align(8)) Gallop_ResponseCommon_Fields {
	struct Gallop_DataHeader_o* data_headers;
};

struct System_String_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_CompareTo;
	VirtualInvokeData _5_Clone;
	VirtualInvokeData _6_GetTypeCode;
	VirtualInvokeData _7_System_IConvertible_ToBoolean;
	VirtualInvokeData _8_System_IConvertible_ToChar;
	VirtualInvokeData _9_System_IConvertible_ToSByte;
	VirtualInvokeData _10_System_IConvertible_ToByte;
	VirtualInvokeData _11_System_IConvertible_ToInt16;
	VirtualInvokeData _12_System_IConvertible_ToUInt16;
	VirtualInvokeData _13_System_IConvertible_ToInt32;
	VirtualInvokeData _14_System_IConvertible_ToUInt32;
	VirtualInvokeData _15_System_IConvertible_ToInt64;
	VirtualInvokeData _16_System_IConvertible_ToUInt64;
	VirtualInvokeData _17_System_IConvertible_ToSingle;
	VirtualInvokeData _18_System_IConvertible_ToDouble;
	VirtualInvokeData _19_System_IConvertible_ToDecimal;
	VirtualInvokeData _20_System_IConvertible_ToDateTime;
	VirtualInvokeData _21_ToString;
	VirtualInvokeData _22_System_IConvertible_ToType;
	VirtualInvokeData _23_System_Collections_IEnumerable_GetEnumerator;
	VirtualInvokeData _24_CompareTo;
	VirtualInvokeData _25_System_Collections_Generic_IEnumerable_System_Char__GetEnumerator;
	VirtualInvokeData _26_Equals;
};

struct System_String_c {
	Il2CppClass_1 _1;
	struct System_String_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_String_VTable vtable;
};

struct __declspec(align(8)) System_String_Fields {
	int32_t m_stringLength;
	uint16_t m_firstChar;
};

struct System_String_o {
	System_String_c* klass;
	void* monitor;
	System_String_Fields fields;
};

struct __declspec(align(8)) Gallop_RequestCommon_Fields {
	int64_t viewer_id;
	int32_t device;
	struct System_String_o* device_id;
	struct System_String_o* device_name;
	struct System_String_o* graphics_device_name;
	struct System_String_o* ip_address;
	struct System_String_o* platform_os_version;
	struct System_String_o* carrier;
	int64_t keychain;
	struct System_String_o* locale;
	struct System_String_o* button_info;
	struct System_String_o* dmm_viewer_id;
	struct System_String_o* dmm_onetime_token;
};

struct Gallop_RequestBase_GachaExecResponse__Fields : Gallop_RequestCommon_Fields {
};

struct Gallop_GachaExecRequest_Fields : Gallop_RequestBase_GachaExecResponse__Fields {
	int32_t gacha_id;
	int32_t draw_type;
	int32_t draw_num;
	int32_t current_num;
	int32_t current_stock_num;
	int32_t item_id;
};
struct Gallop_GachaExecRequest_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_CreateTask;
};
struct Gallop_GachaExecRequest_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_GachaExecRequest_VTable vtable;
};

struct Gallop_GachaExecRequest_o {
	Gallop_GachaExecRequest_c* klass;
	void* monitor;
	Gallop_GachaExecRequest_Fields fields;
};

struct __declspec(align(8)) Gallop_GachaExecutor_Fields {
	struct Gallop_GachaExecutableUnit_o* _executable;
	struct Gallop_GachaExecRequest_o* _request;
	struct Gallop_GachaTicketCounter_o* _Ticket_k__BackingField;
	bool _IsExecutable_k__BackingField;
	bool _IsCostShortage_k__BackingField;
};

struct Gallop_GachaExecutor_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};

struct Gallop_GachaExecutor_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_GachaExecutor_VTable vtable;
};

struct Gallop_GachaExecutor_o {
	Gallop_GachaExecutor_c* klass;
	void* monitor;
	Gallop_GachaExecutor_Fields fields;
};

struct System_Byte_array {
	Il2CppObject obj;
	Il2CppArrayBounds* bounds;
	il2cpp_array_size_t max_length;
	uint8_t m_Items[65535];
};

struct __declspec(align(8)) Gallop_UserInfo_Fields {
	int64_t viewer_id;
	struct System_String_o* name;
	int32_t honor_id;
	int32_t sex;
	int32_t tutorial_step;
	int32_t leader_chara_id;
	int32_t support_card_id;
	int32_t partner_chara_id;
	int32_t bonus_follow_num;
	struct System_String_o* comment;
	struct System_String_o* birth_day;
	uint64_t fan;
	int32_t directory_level;
	int32_t rank_score;
	int32_t best_team_evaluation_point;
	struct System_String_o* create_time;
	struct System_String_o* update_time;
	int32_t leader_chara_dress_id;
};
struct Gallop_UserInfo_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct Gallop_UserInfo_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_UserInfo_VTable vtable;
};

struct Gallop_UserInfo_o {
	Gallop_UserInfo_c* klass;
	void* monitor;
	Gallop_UserInfo_Fields fields;
};

struct __declspec(align(8)) Gallop_CoinInfo_Fields {
	int32_t coin;
	int32_t fcoin;
};
struct Gallop_CoinInfo_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct Gallop_CoinInfo_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_CoinInfo_VTable vtable;
};
struct Gallop_CoinInfo_o {
	Gallop_CoinInfo_c* klass;
	void* monitor;
	Gallop_CoinInfo_Fields fields;
};

struct __declspec(align(8)) Gallop_MenuBadgeInfo_Fields {
	int32_t present_num;
	int32_t mission_num;
	int32_t view_limited_mission_num;
	int32_t legend_mission_num;
	struct Gallop_UserMission_array* champions_mission_array;
	int32_t training_challenge_mission_num;
	int32_t challenge_match_mission_num;
	int32_t team_building_mission_num;
	int32_t new_gacha_flag;
};
struct Gallop_MenuBadgeInfo_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct Gallop_MenuBadgeInfo_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_MenuBadgeInfo_VTable vtable;
};
struct Gallop_MenuBadgeInfo_o {
	Gallop_MenuBadgeInfo_c* klass;
	void* monitor;
	Gallop_MenuBadgeInfo_Fields fields;
};
struct __declspec(align(8)) Gallop_LoginResponse_CommonResponse_Fields {
	struct Gallop_CommonDefine_o* common_define;
	struct Gallop_UserInfo_o* user_info;
	struct Gallop_CoinInfo_o* coin_info;
	struct Gallop_TrainedChara_array* trained_chara;
	struct Gallop_TrainedCharaFavorite_array* trained_chara_favorite_array;
	struct Gallop_UserChara_array* chara_list;
	struct Gallop_UserCard_array* card_list;
	struct Gallop_UserSupportCard_array* support_card_list;
	struct Gallop_UserSupportCardDeck_array* support_card_deck_array;
	int32_t last_select_support_card_deck_id;
	struct Gallop_UserItem_array* item_list;
	struct Gallop_PieceData_array* piece_list;
	struct Gallop_UserCloth_array* cloth_list;
	struct Gallop_UserCardDress_array* card_dress_array;
	struct Gallop_UserMusic_array* music_list;
	struct System_String_o* res_version;
	struct Gallop_TpInfo_o* tp_info;
	struct Gallop_RpInfo_o* rp_info;
	struct Gallop_GachaBannerInfo_array* gacha_banner_info;
	struct Gallop_GachaCampaignInfo_array* gacha_campaign_info_array;
	struct Gallop_LastCheckedTime_array* user_last_checked_time_list;
	struct Gallop_MenuBadgeInfo_o* menu_badge_info;
	struct Gallop_PaymentPurchasedTimes_array* payment_purchased_times_list;
	struct System_String_o* user_birth;
	struct System_String_o* recheck_dmm_jewel;
	struct Gallop_MainStoryData_array* main_story_data_list;
	struct Gallop_CharacterStoryData_array* character_story_data_list;
	struct Gallop_CircleAtLoad_o* circle_data;
	struct Gallop_SingleModeCharaLight_o* single_mode_chara_light;
	struct Gallop_HomeCharacterDressInfo_o* home_position_info;
	int32_t is_linkage;
	struct Gallop_PaymentSeasonPackInfo_o* season_pack_info;
	struct Gallop_NoteDataForDisplay_array* event_data_array;
	struct Gallop_CharaProfileData_array* chara_profile_array;
	struct Gallop_LoginBonusData_array* login_bonus_list;
	struct Gallop_TeamStadiumTeamData_array* team_data_array;
	struct Gallop_DirectoryCard_array* directory_card_array;
	int32_t add_friend_point;
	int32_t support_user_num;
	struct Gallop_TeamStadiumUser_o* team_stadium_user;
	struct Gallop_DailyRacePlayingInfo_o* daily_race_playing_info;
	struct Gallop_LegendRacePlayingInfo_o* legend_race_playing_info;
	struct Gallop_DailyLegendRacePlayingInfo_o* daily_legend_race_playing_info;
	struct System_Int32_array* single_mode_scenario_id_array;
	int32_t single_mode_rental_succession_num;
	int64_t single_mode_succession_free_rental_time;
	struct Gallop_SingleModeDifficultyInfo_array* single_mode_difficulty_info_array;
	struct Gallop_HonorInfo_o* honor_info;
	struct Gallop_LoginUserTrophyInfo_array* login_trophy_info_array;
	int32_t team_stadium_race_status;
	struct Gallop_LimitedShopInfo_o* limited_shop_info;
	int32_t release_item_flag;
	struct Gallop_HomeStoryDataForDisplay_array* home_story_data_array;
	struct Gallop_ShortEpisodeDataForDisplay_array* short_episode_data_array;
	struct Gallop_HomePosterDataForDisplay_array* home_poster_data_array;
	struct Gallop_TeamStadiumRanking_o* ranking;
	struct Gallop_TeamStadiumBorderLine_o* border_line;
	struct Gallop_TutorialGuideDataForDisplay_array* tutorial_guide_data_array;
	struct System_String_o* last_information_update_time;
	struct Gallop_ChampionsInfo_o* champions_info;
	struct System_Int32_array* release_card_array;
	struct System_Int32_array* unread_announce_id_array;
	struct Gallop_ReleasedEpisodeDataForDisplay_array* released_episode_data_array;
	struct System_Int32_array* stadium_race_chara_id_array;
	struct Gallop_ExtraStoryData_o* extra_story_data_list;
	int32_t story_event_id;
	bool story_event_first_flag;
	struct Gallop_UserMission_array* story_event_mission_list;
	int32_t story_event_roulette_coin_num;
	struct Gallop_UserNoticeData_o* notice_data;
	struct Gallop_TransferEventInfo_o* transfer_event_info;
	struct Gallop_ScenarioRecord_array* scenario_record_array;
	struct Gallop_AddedGachaStockInfo_o* added_gacha_stock_info;
	struct Gallop_TrainedChara_array* practice_partner_chara_array;
	struct Gallop_PracticePartnerOwnerInfo_array* practice_partner_owner_info_array;
	int32_t practice_race_state;
	struct Gallop_JukeboxInfo_o* jukebox_info;
	struct Gallop_JukeboxRequest_o* jukebox_request_history;
	struct Gallop_TrainingChallengeUserInfo_o* training_challenge_user_info;
	struct Gallop_TrainingChallengeExamInfo_array* training_challenge_exam_infos;
	struct Gallop_ValentineReceivedData_o* valentine_campaign_received_array;
	struct Gallop_ChallengeMatchLoadInfo_o* challenge_match_load_info;
	struct Gallop_TalkGalleryList_array* talk_gallery_list;
	int32_t fan_raid_id;
	bool fan_raid_first_flag;
	struct Gallop_TeamBuildingLoadInfo_o* team_building_load_info;
	struct Gallop_StoryFavorite_array* story_favorite_array;
};
struct Gallop_LoginResponse_CommonResponse_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct Gallop_LoginResponse_CommonResponse_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_LoginResponse_CommonResponse_VTable vtable;
};
struct Gallop_LoginResponse_CommonResponse_o {
	Gallop_LoginResponse_CommonResponse_c* klass;
	void* monitor;
	Gallop_LoginResponse_CommonResponse_Fields fields;
};
struct Gallop_LoginResponse_Fields : Gallop_ResponseCommon_Fields {
	struct Gallop_LoginResponse_CommonResponse_o* data;
};
struct Gallop_LoginResponse_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct Gallop_LoginResponse_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_LoginResponse_VTable vtable;
};
struct Gallop_LoginResponse_o {
	Gallop_LoginResponse_c* klass;
	void* monitor;
	Gallop_LoginResponse_Fields fields;
};

struct System_Action_GachaExecResponse__Fields : System_MulticastDelegate_Fields {
};
struct System_Action_GachaExecResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_unknown;
	VirtualInvokeData _6_DynamicInvokeImpl;
	VirtualInvokeData _7_Clone;
	VirtualInvokeData _8_GetMethodImpl;
	VirtualInvokeData _9_GetObjectData;
	VirtualInvokeData _10_GetInvocationList;
	VirtualInvokeData _11_CombineImpl;
	VirtualInvokeData _12_RemoveImpl;
	VirtualInvokeData _13_Invoke;
	VirtualInvokeData _14_BeginInvoke;
	VirtualInvokeData _15_EndInvoke;
};
struct System_Action_GachaExecResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Action_GachaExecResponse__VTable vtable;
};

struct System_Action_GachaExecResponse__o {
	System_Action_GachaExecResponse__c* klass;
	void* monitor;
	System_Action_GachaExecResponse__Fields fields;
};

struct System_Action_HttpManager_SendOption__Fields : System_MulticastDelegate_Fields {
};
struct System_Action_HttpManager_SendOption__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_unknown;
	VirtualInvokeData _6_DynamicInvokeImpl;
	VirtualInvokeData _7_Clone;
	VirtualInvokeData _8_GetMethodImpl;
	VirtualInvokeData _9_GetObjectData;
	VirtualInvokeData _10_GetInvocationList;
	VirtualInvokeData _11_CombineImpl;
	VirtualInvokeData _12_RemoveImpl;
	VirtualInvokeData _13_Invoke;
	VirtualInvokeData _14_BeginInvoke;
	VirtualInvokeData _15_EndInvoke;
};

struct System_Action_HttpManager_SendOption__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Action_HttpManager_SendOption__VTable vtable;
};

struct System_Action_HttpManager_SendOption__o {
	System_Action_HttpManager_SendOption__c* klass;
	void* monitor;
	System_Action_HttpManager_SendOption__Fields fields;
};

struct __declspec(align(8)) Cute_Http_HttpManager_Fields {
	struct System_Action_HttpManager_SendOption__o* _activateOptionCallback;
	struct System_Action_HttpManager_SendOption__o* _deactivateOptionCallback;
	struct System_Collections_Generic_Dictionary_IHttpTask__HttpManager_SendOption__o* _taskOptions;
	struct System_Collections_Generic_Queue_HttpManager_SendOption__o* _taskOptionPool;
	struct System_Collections_Generic_Queue_IHttpTask__o* taskQueue;
	struct Cute_Http_IWebRequest_o* currentOperation;
	float timeOutTime;
	struct Cute_Http_ResponseCache_o* responseCache;
	bool deserializing;
	bool sendNextTask;
	float _ApiSendCoolTime_k__BackingField;
	float _apiSendCoolTimer;
	struct System_String_o* _ServerUrl_k__BackingField;
	struct System_Collections_Generic_Dictionary_string__string__o* defaultHeader;
	struct System_Func_byte____byte____o* _CompressFunc_k__BackingField;
	struct System_Func_byte____byte____o* _DecompressFunc_k__BackingField;
	int32_t _RequestType_k__BackingField;
	struct System_Func_string__Dictionary_string__string___int__o* _GetWWWErrorCodeFunc_k__BackingField;
	struct System_Action_o* _PreProcessForSendTask_k__BackingField;
};
struct Cute_Http_HttpManager_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Cute_Core_IUpdatable_FastUpdate;
};
struct Cute_Http_HttpManager_c {
	Il2CppClass_1 _1;
	struct Cute_Http_HttpManager_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cute_Http_HttpManager_VTable vtable;
};

struct Cute_Http_HttpManager_o {
	Cute_Http_HttpManager_c* klass;
	void* monitor;
	Cute_Http_HttpManager_Fields fields;
};

struct System_Collections_Generic_Dictionary_Entry_TKey__TValue__Fields {
	int32_t hashCode;
	int32_t next;
	Il2CppObject* key;
	Il2CppObject* value;
};

struct System_Collections_Generic_Dictionary_Entry_TKey__TValue__o {
	System_Collections_Generic_Dictionary_Entry_TKey__TValue__Fields fields;
};

struct System_Collections_Generic_Dictionary_Entry_TKey__TValue__array {
	Il2CppObject obj;
	Il2CppArrayBounds* bounds;
	il2cpp_array_size_t max_length;
	System_Collections_Generic_Dictionary_Entry_TKey__TValue__o m_Items[65535];
};

struct __declspec(align(8)) System_Collections_Generic_Dictionary_string__string__Fields {
	struct System_Int32_array* buckets;
	struct System_Collections_Generic_Dictionary_Entry_TKey__TValue__array* entries;
	int32_t count;
	int32_t version;
	int32_t freeList;
	int32_t freeCount;
	struct System_Collections_Generic_IEqualityComparer_TKey__o* comparer;
	struct System_Collections_Generic_Dictionary_KeyCollection_TKey__TValue__o* keys;
	struct System_Collections_Generic_Dictionary_ValueCollection_TKey__TValue__o* values;
	Il2CppObject* _syncRoot;
};

struct System_Collections_Generic_Dictionary_string__string__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_get_Item;
	VirtualInvokeData _5_set_Item;
	VirtualInvokeData _6_System_Collections_Generic_IDictionary_TKey_TValue__get_Keys;
	VirtualInvokeData _7_ContainsKey;
	VirtualInvokeData _8_Add;
	VirtualInvokeData _9_Remove;
	VirtualInvokeData _10_unknown;
	VirtualInvokeData _11_unknown;
	VirtualInvokeData _12_System_Collections_Generic_ICollection_System_Collections_Generic_KeyValuePair_TKey_TValue___get_IsReadOnly;
	VirtualInvokeData _13_System_Collections_Generic_ICollection_System_Collections_Generic_KeyValuePair_TKey_TValue___Add;
	VirtualInvokeData _14_unknown;
	VirtualInvokeData _15_System_Collections_Generic_ICollection_System_Collections_Generic_KeyValuePair_TKey_TValue___Contains;
	VirtualInvokeData _16_System_Collections_Generic_ICollection_System_Collections_Generic_KeyValuePair_TKey_TValue___CopyTo;
	VirtualInvokeData _17_System_Collections_Generic_ICollection_System_Collections_Generic_KeyValuePair_TKey_TValue___Remove;
	VirtualInvokeData _18_System_Collections_Generic_IEnumerable_System_Collections_Generic_KeyValuePair_TKey_TValue___GetEnumerator;
	VirtualInvokeData _19_System_Collections_IEnumerable_GetEnumerator;
	VirtualInvokeData _20_System_Collections_IDictionary_get_Item;
	VirtualInvokeData _21_System_Collections_IDictionary_set_Item;
	VirtualInvokeData _22_System_Collections_IDictionary_get_Keys;
	VirtualInvokeData _23_System_Collections_IDictionary_get_Values;
	VirtualInvokeData _24_System_Collections_IDictionary_Contains;
	VirtualInvokeData _25_System_Collections_IDictionary_Add;
	VirtualInvokeData _26_Clear;
	VirtualInvokeData _27_System_Collections_IDictionary_get_IsReadOnly;
	VirtualInvokeData _28_System_Collections_IDictionary_get_IsFixedSize;
	VirtualInvokeData _29_System_Collections_IDictionary_GetEnumerator;
	VirtualInvokeData _30_System_Collections_IDictionary_Remove;
	VirtualInvokeData _31_System_Collections_ICollection_CopyTo;
	VirtualInvokeData _32_unknown;
	VirtualInvokeData _33_System_Collections_ICollection_get_SyncRoot;
	VirtualInvokeData _34_System_Collections_ICollection_get_IsSynchronized;
	VirtualInvokeData _35_TryGetValue;
	VirtualInvokeData _36_get_Count;
	VirtualInvokeData _37_unknown;
	VirtualInvokeData _38_unknown;
	VirtualInvokeData _39_GetObjectData;
	VirtualInvokeData _40_OnDeserialization;
};
struct System_Collections_Generic_Dictionary_string__string__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Collections_Generic_Dictionary_string__string__VTable vtable;
};



struct System_Collections_Generic_Dictionary_string__string__o {
	System_Collections_Generic_Dictionary_string__string__c* klass;
	void* monitor;
	System_Collections_Generic_Dictionary_string__string__Fields fields;
};

struct __declspec(align(8)) Gallop_ToolStartSessionTask_Fields {
	struct System_Byte_array* postData;
	struct System_Action_ToolStartSessionResponse__o* onSuccess;
	struct System_Action_ErrorType__int__ToolStartSessionResponse__o* onError;
	struct System_Collections_Generic_Dictionary_string__string__o* headers;
	struct Cute_Http_IWebRequest_o* request;
};
struct Gallop_ToolStartSessionTask_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_get_IsCompressed;
	VirtualInvokeData _5_get_CacheTime;
	VirtualInvokeData _6_Send;
	VirtualInvokeData _7_Deserialize;
	VirtualInvokeData _8_OnError;
	VirtualInvokeData _9_SetHeader;
};
struct Gallop_ToolStartSessionTask_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_ToolStartSessionTask_VTable vtable;
};

struct Gallop_ToolStartSessionTask_o {
	Gallop_ToolStartSessionTask_c* klass;
	void* monitor;
	Gallop_ToolStartSessionTask_Fields fields;
};


struct System_Delegate_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_unknown;
	VirtualInvokeData _6_DynamicInvokeImpl;
	VirtualInvokeData _7_Clone;
	VirtualInvokeData _8_GetMethodImpl;
	VirtualInvokeData _9_GetObjectData;
	VirtualInvokeData _10_GetInvocationList;
	VirtualInvokeData _11_CombineImpl;
	VirtualInvokeData _12_RemoveImpl;
};
struct System_Delegate_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Delegate_VTable vtable;
};
struct System_Delegate_o {
	System_Delegate_c* klass;
	void* monitor;
	System_Delegate_Fields fields;
};

struct System_Delegate_array {
	Il2CppObject obj;
	Il2CppArrayBounds* bounds;
	il2cpp_array_size_t max_length;
	System_Delegate_o* m_Items[65535];
};
struct System_Action_DataLinkChainByTransitionCodeResponse__Fields : System_MulticastDelegate_Fields {
};
struct System_Action_DataLinkChainByTransitionCodeResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_unknown;
	VirtualInvokeData _6_DynamicInvokeImpl;
	VirtualInvokeData _7_Clone;
	VirtualInvokeData _8_GetMethodImpl;
	VirtualInvokeData _9_GetObjectData;
	VirtualInvokeData _10_GetInvocationList;
	VirtualInvokeData _11_CombineImpl;
	VirtualInvokeData _12_RemoveImpl;
	VirtualInvokeData _13_Invoke;
	VirtualInvokeData _14_BeginInvoke;
	VirtualInvokeData _15_EndInvoke;
};
struct System_Action_DataLinkChainByTransitionCodeResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Action_DataLinkChainByTransitionCodeResponse__VTable vtable;
};
struct System_Action_DataLinkChainByTransitionCodeResponse__o {
	System_Action_DataLinkChainByTransitionCodeResponse__c* klass;
	void* monitor;
	System_Action_DataLinkChainByTransitionCodeResponse__Fields fields;
};


struct System_Action_DataLinkGetByTransitionCodeResponse__Fields : System_MulticastDelegate_Fields {
};


struct System_Action_DataLinkGetByTransitionCodeResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_unknown;
	VirtualInvokeData _6_DynamicInvokeImpl;
	VirtualInvokeData _7_Clone;
	VirtualInvokeData _8_GetMethodImpl;
	VirtualInvokeData _9_GetObjectData;
	VirtualInvokeData _10_GetInvocationList;
	VirtualInvokeData _11_CombineImpl;
	VirtualInvokeData _12_RemoveImpl;
	VirtualInvokeData _13_Invoke;
	VirtualInvokeData _14_BeginInvoke;
	VirtualInvokeData _15_EndInvoke;
};
struct System_Action_DataLinkGetByTransitionCodeResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Action_DataLinkGetByTransitionCodeResponse__VTable vtable;
};

struct System_Action_DataLinkGetByTransitionCodeResponse__o {
	System_Action_DataLinkGetByTransitionCodeResponse__c* klass;
	void* monitor;
	System_Action_DataLinkGetByTransitionCodeResponse__Fields fields;
};

struct __declspec(align(8)) Gallop_DataTransition___c__DisplayClass20_0_Fields {
	int64_t viewerId;
	struct System_String_o* password;
	struct System_Action_DataLinkGetByTransitionCodeResponse__o* onSuccess;
	struct System_Action_ErrorType__int__o* onError;
};

struct Gallop_DataTransition___c__DisplayClass20_0_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};

struct Gallop_DataTransition___c__DisplayClass20_0_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_DataTransition___c__DisplayClass20_0_VTable vtable;
};

struct Gallop_DataTransition___c__DisplayClass20_0_o {
	Gallop_DataTransition___c__DisplayClass20_0_c* klass;
	void* monitor;
	Gallop_DataTransition___c__DisplayClass20_0_Fields fields;
};

struct __declspec(align(8)) Gallop_DataTransition___c_Fields {
};


struct Gallop_DataTransition___c_StaticFields {
	struct Gallop_DataTransition___c_o* __9;
	struct System_Action_DialogCommon__o* __9__4_0;
	struct UnityEngine_Events_UnityAction_o* __9__5_0;
	struct UnityEngine_Events_UnityAction_o* __9__5_1;
	struct System_Action_DialogCommon__o* __9__6_0;
	struct System_Action_DataLinkGetByTransitionCodeResponse__o* __9__8_1;
	struct System_Action_ErrorType__int__o* __9__8_2;
	struct System_Action_DataLinkChainByTransitionCodeResponse__o* __9__11_1;
	struct System_Action_DialogCommon__o* __9__12_0;
	struct System_Action_DialogCommon__o* __9__13_0;
	struct System_Action_DataLinkPublishTransitionCodeResponse__o* __9__14_1;
	struct System_Action_DialogCommon__o* __9__16_0;
	struct System_Action_o* __9__20_1;
};

struct Gallop_DataTransition___c_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct Gallop_DataTransition___c_c {
	Il2CppClass_1 _1;
	struct Gallop_DataTransition___c_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_DataTransition___c_VTable vtable;
};

struct Gallop_DataTransition___c_o {
	Gallop_DataTransition___c_c* klass;
	void* monitor;
	Gallop_DataTransition___c_Fields fields;
};


struct System_Action_PresentIndexResponse__Fields : System_MulticastDelegate_Fields {
};

struct System_Action_PresentIndexResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_unknown;
	VirtualInvokeData _6_DynamicInvokeImpl;
	VirtualInvokeData _7_Clone;
	VirtualInvokeData _8_GetMethodImpl;
	VirtualInvokeData _9_GetObjectData;
	VirtualInvokeData _10_GetInvocationList;
	VirtualInvokeData _11_CombineImpl;
	VirtualInvokeData _12_RemoveImpl;
	VirtualInvokeData _13_Invoke;
	VirtualInvokeData _14_BeginInvoke;
	VirtualInvokeData _15_EndInvoke;
};

struct System_Action_PresentIndexResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Action_PresentIndexResponse__VTable vtable;
};


struct System_Action_PresentIndexResponse__o {
	System_Action_PresentIndexResponse__c* klass;
	void* monitor;
	System_Action_PresentIndexResponse__Fields fields;
};


struct __declspec(align(8)) Gallop_MainGameInitializer__StartSession_d__21_Fields {
	int32_t __1__state;
	Il2CppObject* __2__current;
	struct Gallop_MainGameInitializer___c__DisplayClass21_0_o* __8__1;
	struct System_Action_ToolStartSessionResponse_CommonResponse__bool__o* onSuccess;
};
struct Gallop_MainGameInitializer__StartSession_d__21_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_System_Collections_Generic_IEnumerator_System_Object__get_Current;
	VirtualInvokeData _5_System_IDisposable_Dispose;
	VirtualInvokeData _6_MoveNext;
	VirtualInvokeData _7_System_Collections_IEnumerator_get_Current;
	VirtualInvokeData _8_System_Collections_IEnumerator_Reset;
};
struct Gallop_MainGameInitializer__StartSession_d__21_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_MainGameInitializer__StartSession_d__21_VTable vtable;
};
struct Gallop_MainGameInitializer__StartSession_d__21_o {
	Gallop_MainGameInitializer__StartSession_d__21_c* klass;
	void* monitor;
	Gallop_MainGameInitializer__StartSession_d__21_Fields fields;
};

struct Gallop_ResponseCommon_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct Gallop_ResponseCommon_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_ResponseCommon_VTable vtable;
};
struct Gallop_ResponseCommon_o {
	Gallop_ResponseCommon_c* klass;
	void* monitor;
	Gallop_ResponseCommon_Fields fields;
};


struct Gallop_MonoSingleton_SaveDataManager__StaticFields {
	bool _isApplicationQuit;
	struct Gallop_SaveDataManager_o* _instance;
	struct UnityEngine_GameObject_o* _parentObject;
};

struct Gallop_MonoFunctionSealedBaseForMonoSingleton_Fields : UnityEngine_MonoBehaviour_Fields {
};

struct Gallop_MonoSingleton_SaveDataManager__Fields : Gallop_MonoFunctionSealedBaseForMonoSingleton_Fields {
};
struct __declspec(align(8)) LibNative_Sqlite3_Connection_Fields {
	intptr_t _DBHandle_k__BackingField;
	struct System_String_o* _dbPath_k__BackingField;
};
struct LibNative_Sqlite3_Connection_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_Dispose;
	VirtualInvokeData _6_CloseDB;
};
struct LibNative_Sqlite3_Connection_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	LibNative_Sqlite3_Connection_VTable vtable;
};
struct LibNative_Sqlite3_Connection_o {
	LibNative_Sqlite3_Connection_c* klass;
	void* monitor;
	LibNative_Sqlite3_Connection_Fields fields;
};

struct Gallop_ApplicationSettingSaveLoader_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Dispose;
};
struct Gallop_ApplicationSettingSaveLoader_c {
	Il2CppClass_1 _1;
	struct Gallop_ApplicationSettingSaveLoader_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_ApplicationSettingSaveLoader_VTable vtable;
};
struct __declspec(align(8)) Gallop_ApplicationSettingSaveLoader_Fields {
	struct Gallop_SQLiteSaveLoadHelper_ApplicationSettingSaveLoader_SaveData__o* _helper;
	struct Gallop_ApplicationSettingSaveLoader_SaveData_o* _container;
};
struct Gallop_ApplicationSettingSaveLoader_o {
	Gallop_ApplicationSettingSaveLoader_c* klass;
	void* monitor;
	Gallop_ApplicationSettingSaveLoader_Fields fields;
};

struct Gallop_SaveDataManager_Fields : Gallop_MonoSingleton_SaveDataManager__Fields {
	struct LibNative_Sqlite3_Connection_o* _sqliteDBProxy;
	struct Gallop_ApplicationSettingSaveLoader_o* _applicationSettingSaveLoder;
};
struct Gallop_SaveDataManager_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Awake;
	VirtualInvokeData _5_OnInitialize;
	VirtualInvokeData _6_OnFinalize;
	VirtualInvokeData _7_OnApplicationQuit;
};
struct Gallop_SaveDataManager_c {
	Il2CppClass_1 _1;
	struct Gallop_SaveDataManager_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_SaveDataManager_VTable vtable;
};
struct Gallop_SaveDataManager_o {
	Gallop_SaveDataManager_c* klass;
	void* monitor;
	Gallop_SaveDataManager_Fields fields;
};

struct CodeStage_AntiCheat_ObscuredTypes_ObscuredLong_Fields {
	int64_t currentCryptoKey;
	int64_t hiddenValue;
	bool inited;
	int64_t fakeValue;
	bool fakeValueActive;
};

struct __declspec(align(8)) Gallop_Singleton_TempData__Fields {
};

struct CodeStage_AntiCheat_ObscuredTypes_ObscuredLong_o {
	CodeStage_AntiCheat_ObscuredTypes_ObscuredLong_Fields fields;
};

struct System_TimeSpan_Fields {
	int64_t _ticks;
};

struct System_TimeSpan_o {
	System_TimeSpan_Fields fields;
};

struct __declspec(align(8)) Gallop_TempData_TrainingChallengeTempData_Fields {
	int32_t _MissionClearNum_k__BackingField;
};

struct CodeStage_AntiCheat_ObscuredTypes_ObscuredInt_Fields {
	int32_t currentCryptoKey;
	int32_t hiddenValue;
	bool inited;
	int32_t fakeValue;
	bool fakeValueActive;
};
struct CodeStage_AntiCheat_ObscuredTypes_ObscuredInt_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_ToString;
	VirtualInvokeData _5_Equals;
	VirtualInvokeData _6_CompareTo;
	VirtualInvokeData _7_CompareTo;
	VirtualInvokeData _8_CompareTo;
};
struct CodeStage_AntiCheat_ObscuredTypes_ObscuredInt_c {
	Il2CppClass_1 _1;
	struct CodeStage_AntiCheat_ObscuredTypes_ObscuredInt_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	CodeStage_AntiCheat_ObscuredTypes_ObscuredInt_VTable vtable;
};

struct CodeStage_AntiCheat_ObscuredTypes_ObscuredInt_o {
	CodeStage_AntiCheat_ObscuredTypes_ObscuredInt_Fields fields;
};

struct CodeStage_AntiCheat_ObscuredTypes_ObscuredBool_Fields {
	uint8_t currentCryptoKey;
	int32_t hiddenValue;
	bool inited;
	bool fakeValue;
	bool fakeValueActive;
};

struct CodeStage_AntiCheat_ObscuredTypes_ObscuredBool_o {
	CodeStage_AntiCheat_ObscuredTypes_ObscuredBool_Fields fields;
};

struct __declspec(align(8)) System_Collections_Generic_List_int__Fields {
	struct System_Int32_array* _items;
	int32_t _size;
	int32_t _version;
	Il2CppObject* _syncRoot;
};
struct System_Collections_Generic_List_int__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_set_Item;
	VirtualInvokeData _6_IndexOf;
	VirtualInvokeData _7_Insert;
	VirtualInvokeData _8_unknown;
	VirtualInvokeData _9_unknown;
	VirtualInvokeData _10_System_Collections_Generic_ICollection_T__get_IsReadOnly;
	VirtualInvokeData _11_Add;
	VirtualInvokeData _12_unknown;
	VirtualInvokeData _13_Contains;
	VirtualInvokeData _14_CopyTo;
	VirtualInvokeData _15_Remove;
	VirtualInvokeData _16_System_Collections_Generic_IEnumerable_T__GetEnumerator;
	VirtualInvokeData _17_System_Collections_IEnumerable_GetEnumerator;
	VirtualInvokeData _18_System_Collections_IList_get_Item;
	VirtualInvokeData _19_System_Collections_IList_set_Item;
	VirtualInvokeData _20_System_Collections_IList_Add;
	VirtualInvokeData _21_System_Collections_IList_Contains;
	VirtualInvokeData _22_Clear;
	VirtualInvokeData _23_System_Collections_IList_get_IsReadOnly;
	VirtualInvokeData _24_System_Collections_IList_get_IsFixedSize;
	VirtualInvokeData _25_System_Collections_IList_IndexOf;
	VirtualInvokeData _26_System_Collections_IList_Insert;
	VirtualInvokeData _27_System_Collections_IList_Remove;
	VirtualInvokeData _28_RemoveAt;
	VirtualInvokeData _29_System_Collections_ICollection_CopyTo;
	VirtualInvokeData _30_unknown;
	VirtualInvokeData _31_System_Collections_ICollection_get_SyncRoot;
	VirtualInvokeData _32_System_Collections_ICollection_get_IsSynchronized;
	VirtualInvokeData _33_get_Item;
	VirtualInvokeData _34_get_Count;
};
struct System_Collections_Generic_List_int__c {
	Il2CppClass_1 _1;
	struct System_Collections_Generic_List_int__StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Collections_Generic_List_int__VTable vtable;
};
struct System_Collections_Generic_List_int__o {
	System_Collections_Generic_List_int__c* klass;
	void* monitor;
	System_Collections_Generic_List_int__Fields fields;
};

struct Gallop_TempData_Fields : Gallop_Singleton_TempData__Fields {
	struct System_Collections_Generic_List_int__o* _championsClearMissionIdList;
	struct Gallop_TempData_ChampionsTempData_o* _ChampionsData_k__BackingField;
	struct Gallop_ChampionsRewardInfo_array* _ChampionsRewardInfoArray_k__BackingField;
	struct CodeStage_AntiCheat_ObscuredTypes_ObscuredLong_o _serverTime;
	struct System_TimeSpan_o _deviceStartUpTime;
	struct Gallop_TempData_ClickButtonTempData_o* ClickButtonPosData;
	struct Gallop_TempData_HomeTempData_o* HomeData;
	struct System_Collections_Generic_Dictionary_int__EventSkill____o* _SupportCardEventSkillDictionary_k__BackingField;
	struct System_Collections_Generic_Dictionary_int__EventSkill____o* _CardEventSkillDictionary_k__BackingField;
	bool _NewGachaFlag_k__BackingField;
	struct CodeStage_AntiCheat_ObscuredTypes_ObscuredInt_o _MissionClearNum_k__BackingField;
	struct System_Collections_Generic_Queue_TempData_MissionNotice__o* MissionNoticeQueue;
	int32_t MissionViewLatestTabMissionType;
	int32_t _ViewLimitedMissionNum_k__BackingField;
	struct CodeStage_AntiCheat_ObscuredTypes_ObscuredInt_o _MissionRecmmendedCardId_k__BackingField;
	struct CodeStage_AntiCheat_ObscuredTypes_ObscuredInt_o _PresentNotReceivedNum_k__BackingField;
	struct CodeStage_AntiCheat_ObscuredTypes_ObscuredBool_o _ExistNewInfomation_k__BackingField;
	int64_t _InfomationUpDateTime_k__BackingField;
	struct Gallop_TempData_StoryCommonTempData_o* StoryCommonData;
	struct Gallop_TempData_EpisodeTempData_o* EpisodeData;
	bool IsInMainStory;
	struct Gallop_TempData_SingleModeTempData_o* SingleModeData;
	struct Gallop_TempData_LegendRaceTempData_o* LegendRaceData;
	struct Gallop_TempData_DailyLegendRaceTempData_o* DailyLegendRaceData;
	struct Gallop_TempData_DailyRaceTempData_o* DailyRaceData;
	struct Gallop_TempData_CharacterNoteTempData_o* CharacterNoteData;
	struct System_String_o* _TransitionPassword_k__BackingField;
	struct System_String_o* _TransitionRequestUserName_k__BackingField;
	struct System_Action_o* _TransitionSetPassCallback_k__BackingField;
	struct CodeStage_AntiCheat_ObscuredTypes_ObscuredInt_o _FriendNewFollowerNum_k__BackingField;
	struct Gallop_TempData_RaceTempData_o* RaceData;
	struct Gallop_TempData_TrophyRoomTempData_o* TrophyRoomData;
	struct Gallop_TempData_StoryEventTempData_o* StoryEventData;
	struct Gallop_TempData_StoryExtraTempData_o* StoryExtraData;
	struct Gallop_TempData_RoomMatchTempData_o* RoomMatchData;
	struct Gallop_TempData_ProfileCardTempData_o* TrainerProfileCardData;
	struct Gallop_TempData_ProfileCardTempData_o* TrainerProfileCardDataForHonorView;
	struct Gallop_TempData_ProfileCardTempData_o* TrainerProfileCardOriginDataForHonorView;
	struct System_String_o* DeviceIdentiferOnServer;
	struct Gallop_TempData_TransferEventTempData_o* TransferEventData;
	struct Gallop_TempData_GalleryTempData_o* GalleryData;
	struct Gallop_TempData_PracticeRaceTempData_o* PracticeRaceData;
	bool PlayFirstTransitionDefalutBgm;
	float JukeboxMusicStartTimeOffset;
	bool ShowLikeFromOthers;
	struct Gallop_TempData_GachaTempData_o* GachaData;
	struct Gallop_TempData_GachaResultTempData_o* GachaResult;
	struct Gallop_TempData_ShopTempData_o* ShopData;
	struct Gallop_TempData_ShopItemConditionTempData_o* ShopItemConditionData;
	struct Gallop_TempData_ShopLimitedSalesItemListTempData_o* ShopLimitedSalesItemListData;
	struct Gallop_TempData_TrainingChallengeTempData_o* TrainingChallengeData;
};
struct Gallop_TempData_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_DestroyInstanceInternal;
	VirtualInvokeData _5_OnInitialize;
	VirtualInvokeData _6_OnFinalize;
};
struct Gallop_TempData_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_TempData_VTable vtable;
};
struct Gallop_TempData_o {
	Gallop_TempData_c* klass;
	void* monitor;
	Gallop_TempData_Fields fields;
};

struct __declspec(align(8)) Gallop_ViewControllerBase_TitleView__Fields {
	int32_t _viewId;
	struct Gallop_TitleView_o* _view;
	struct Gallop_IViewInfo_o* _viewInfo;
	struct Gallop_ISceneController_o* _parentSceneController;
};

struct UnityEngine_Vector2_Fields {
	float x;
	float y;
};

struct UnityEngine_Vector2_o {
	UnityEngine_Vector2_Fields fields;
};

struct Gallop_TitleViewController_Fields : Gallop_ViewControllerBase_TitleView__Fields {
	struct UnityEngine_Vector2_o _gaugeSize;
	float _gaugeWidth;
	bool _isDisplayViewerId;
};

struct Gallop_TitleViewController_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_GetViewId;
	VirtualInvokeData _5_unknown;
	VirtualInvokeData _6_SetViewBase;
	VirtualInvokeData _7_GetViewBase;
	VirtualInvokeData _8_GetViewInfo;
	VirtualInvokeData _9_unknown;
	VirtualInvokeData _10_unknown;
	VirtualInvokeData _11_unknown;
	VirtualInvokeData _12_unknown;
	VirtualInvokeData _13_unknown;
	VirtualInvokeData _14_unknown;
	VirtualInvokeData _15_unknown;
	VirtualInvokeData _16_unknown;
	VirtualInvokeData _17_unknown;
	VirtualInvokeData _18_unknown;
	VirtualInvokeData _19_unknown;
	VirtualInvokeData _20_unknown;
	VirtualInvokeData _21_unknown;
	VirtualInvokeData _22_unknown;
	VirtualInvokeData _23_unknown;
	VirtualInvokeData _24_unknown;
	VirtualInvokeData _25_unknown;
	VirtualInvokeData _26_unknown;
	VirtualInvokeData _27_unknown;
	VirtualInvokeData _28_unknown;
	VirtualInvokeData _29_unknown;
	VirtualInvokeData _30_unknown;
	VirtualInvokeData _31_unknown;
	VirtualInvokeData _32_unknown;
	VirtualInvokeData _33_unknown;
	VirtualInvokeData _34_unknown;
	VirtualInvokeData _35_unknown;
	VirtualInvokeData _36_unknown;
	VirtualInvokeData _37_unknown;
	VirtualInvokeData _38_unknown;
	VirtualInvokeData _39_unknown;
	VirtualInvokeData _40_unknown;
	VirtualInvokeData _41_unknown;
	VirtualInvokeData _42_unknown;
	VirtualInvokeData _43_PlayInViewFromSceneManager;
	VirtualInvokeData _44_PlayOutViewFromSceneManager;
	VirtualInvokeData _45_unknown;
	VirtualInvokeData _46_unknown;
	VirtualInvokeData _47_GetContentsRoot;
	VirtualInvokeData _48_unknown;
	VirtualInvokeData _49_unknown;
	VirtualInvokeData _50_unknown;
	VirtualInvokeData _51_unknown;
	VirtualInvokeData _52_unknown;
	VirtualInvokeData _53_unknown;
	VirtualInvokeData _54_unknown;
	VirtualInvokeData _55_unknown;
	VirtualInvokeData _56_SetChildViewInfo;
	VirtualInvokeData _57_SetFromSceneManager;
	VirtualInvokeData _58_RegisterDownload;
	VirtualInvokeData _59_InitializeView;
	VirtualInvokeData _60_InitializeEachPlayIn;
	VirtualInvokeData _61_BeginView;
	VirtualInvokeData _62_FixedUpdateView;
	VirtualInvokeData _63_UpdateView;
	VirtualInvokeData _64_EndView;
	VirtualInvokeData _65_FinalizeView;
	VirtualInvokeData _66_GetDynamicBgId;
	VirtualInvokeData _67_GetDynamicBgmId;
	VirtualInvokeData _68_GetDynamicBgmCueInfo;
	VirtualInvokeData _69_GetDynamicHeaderTitleTextId;
	VirtualInvokeData _70_GetDynamicTutorialGuideId;
	VirtualInvokeData _71_GetBackableStateInfo;
	VirtualInvokeData _72_IgnoreBgm;
	VirtualInvokeData _73_OverrideDynamicNowLoadingType;
	VirtualInvokeData _74_GetDynamicFooterType;
	VirtualInvokeData _75_GetDynamicUseFooter;
	VirtualInvokeData _76_PreRegisterDownload;
	VirtualInvokeData _77_UpdateViewPre;
	VirtualInvokeData _78_UpdateViewPost;
	VirtualInvokeData _79_LateUpdateViewPre;
	VirtualInvokeData _80_LateUpdateView;
	VirtualInvokeData _81_LateUpdateViewPost;
	VirtualInvokeData _82_UpdateViewBeforeLoadingOutPre;
	VirtualInvokeData _83_UpdateViewBeforeLoadingOut;
	VirtualInvokeData _84_UpdateViewBeforeLoadingOutPost;
	VirtualInvokeData _85_LateUpdateViewBeforeLoadingOutPre;
	VirtualInvokeData _86_LateUpdateViewBeforeLoadingOut;
	VirtualInvokeData _87_LateUpdateViewBeforeLoadingOutPost;
	VirtualInvokeData _88_UpdateViewBeforeLoadingInPre;
	VirtualInvokeData _89_UpdateViewBeforeLoadingIn;
	VirtualInvokeData _90_UpdateViewBeforeLoadingInPost;
	VirtualInvokeData _91_LateUpdateViewBeforeLoadingInPre;
	VirtualInvokeData _92_LateUpdateViewBeforeLoadingIn;
	VirtualInvokeData _93_LateUpdateViewBeforeLoadingInPost;
	VirtualInvokeData _94_OnClickBackButton;
	VirtualInvokeData _95_OnClickOsBackKey;
	VirtualInvokeData _96_GetChangeViewOrientation;
	VirtualInvokeData _97_PlayInView;
	VirtualInvokeData _98_PlayOutView;
	VirtualInvokeData _99_GetAnimationDataList;
	VirtualInvokeData _100_GetBackButtonAnimationDelayTime;
};

struct Gallop_TitleViewController_c {
	Il2CppClass_1 _1;
	struct Gallop_TitleViewController_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_TitleViewController_VTable vtable;
};
struct Gallop_TitleViewController_o {
	Gallop_TitleViewController_c* klass;
	void* monitor;
	Gallop_TitleViewController_Fields fields;
};

struct __declspec(align(8)) Gallop_GameSystem__InitializeGame_d__33_Fields {
	int32_t __1__state;
	Il2CppObject* __2__current;
	struct Gallop_GameSystem_o* __4__this;
	int32_t _i_5__2;
};
struct Gallop_GameSystem__InitializeGame_d__33_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_System_Collections_Generic_IEnumerator_System_Object__get_Current;
	VirtualInvokeData _5_System_IDisposable_Dispose;
	VirtualInvokeData _6_MoveNext;
	VirtualInvokeData _7_System_Collections_IEnumerator_get_Current;
	VirtualInvokeData _8_System_Collections_IEnumerator_Reset;
};
struct Gallop_GameSystem__InitializeGame_d__33_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_GameSystem__InitializeGame_d__33_VTable vtable;
};
struct Gallop_GameSystem__InitializeGame_d__33_o {
	Gallop_GameSystem__InitializeGame_d__33_c* klass;
	void* monitor;
	Gallop_GameSystem__InitializeGame_d__33_Fields fields;
};

struct Gallop_MonoSingleton_GameSystem__Fields : Gallop_MonoFunctionSealedBaseForMonoSingleton_Fields {
};

struct Gallop_GameSystem_Fields : Gallop_MonoSingleton_GameSystem__Fields {
	struct UnityEngine_GameObject_o* _systemManagerRoot;
	struct UnityEngine_GameObject_o* _functionalManagerRoot;
	int32_t _systemState;
	bool _isColliderSyncTransform;
	bool _isOpenDownloadAllDialogWithTitle;
	struct Gallop_SceneManager_o* _sceneManagerInstance;
	struct Gallop_ModelControllerUpdater_o* _modelControllerUpdaterInstance;
};
struct Gallop_GameSystem_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Awake;
	VirtualInvokeData _5_OnInitialize;
	VirtualInvokeData _6_OnFinalize;
	VirtualInvokeData _7_OnApplicationQuit;
};
struct Gallop_GameSystem_c {
	Il2CppClass_1 _1;
	struct Gallop_GameSystem_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_GameSystem_VTable vtable;
};
struct Gallop_GameSystem_o {
	Gallop_GameSystem_c* klass;
	void* monitor;
	Gallop_GameSystem_Fields fields;
};

struct Gallop_RequestBase_ToolStartSessionResponse__Fields : Gallop_RequestCommon_Fields {
};

struct Gallop_ToolStartSessionRequest_Fields : Gallop_RequestBase_ToolStartSessionResponse__Fields {
};
struct Gallop_ToolStartSessionRequest_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_CreateTask;
};
struct Gallop_ToolStartSessionRequest_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_ToolStartSessionRequest_VTable vtable;
};
struct Gallop_ToolStartSessionRequest_o {
	Gallop_ToolStartSessionRequest_c* klass;
	void* monitor;
	Gallop_ToolStartSessionRequest_Fields fields;
};

struct __declspec(align(8)) Gallop_GachaResultData_Fields {
	int32_t card_type;
	int32_t card_id;
	int32_t piece_id;
	int32_t common_item_category;
	int32_t common_item_id;
	int32_t convert_piece_num;
	int32_t convert_common_item_num;
	int32_t additional_piece_num;
	int32_t new_flag;
	int32_t win_prize;
};
struct Gallop_GachaResultData_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct Gallop_GachaResultData_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_GachaResultData_VTable vtable;
};
struct Gallop_GachaResultData_o {
	Gallop_GachaResultData_c* klass;
	void* monitor;
	Gallop_GachaResultData_Fields fields;
};

struct Gallop_GachaResultData_array {
	Il2CppObject obj;
	Il2CppArrayBounds* bounds;
	il2cpp_array_size_t max_length;
	Gallop_GachaResultData_o* m_Items[65535];
};

struct __declspec(align(8)) Gallop_GachaExecResponse_CommonResponse_Fields {
	struct Gallop_GachaResultData_array* gacha_result_list;
	struct Gallop_ResponseItem_array* bonus_item_array;
	struct Gallop_CoinInfo_o* coin_info;
	struct Gallop_RewardSummaryInfo_o* reward_summary_info;
	struct Gallop_ResponseItem_array* item_list;
	struct Gallop_GachaLimitItemInfo_o* limit_item_info;
};
struct Gallop_GachaExecResponse_CommonResponse_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct Gallop_GachaExecResponse_CommonResponse_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_GachaExecResponse_CommonResponse_VTable vtable;
};
struct Gallop_GachaExecResponse_CommonResponse_o {
	Gallop_GachaExecResponse_CommonResponse_c* klass;
	void* monitor;
	Gallop_GachaExecResponse_CommonResponse_Fields fields;
};
struct Gallop_GachaExecResponse_Fields : Gallop_ResponseCommon_Fields {
	struct Gallop_GachaExecResponse_CommonResponse_o* data;
};
struct Gallop_GachaExecResponse_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct Gallop_GachaExecResponse_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Gallop_GachaExecResponse_VTable vtable;
};
struct Gallop_GachaExecResponse_o {
	Gallop_GachaExecResponse_c* klass;
	void* monitor;
	Gallop_GachaExecResponse_Fields fields;
};