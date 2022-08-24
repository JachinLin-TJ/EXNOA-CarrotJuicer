#include <filesystem>
#include <iostream>
#include <locale>
#include <string>
#include <thread>
#include <Windows.h>
#include <MinHook.h>
#include <thread>
#include <unordered_map>
#include "msgpack11.hpp"
#include "config.hpp"
#include "edb.hpp"
#include "responses.hpp"
#include "notifier.hpp"
#include "requests.hpp"
#include "PEDump.h"
#include "base64.h"
#include <cstdlib>
#include "msgpack.hpp"
#include <cstring>
#include <cinttypes>
#include "il2cpp-class.h"
#include "il2cpp-tabledefs.h"
#include "il2cpp.h"
#define DO_API(r, n, p) r (*n) p
#include "il2cpp-api-functions.h"
#undef DO_API
//#define LOOP

std::unordered_map<int, std::unordered_map<std::string, std::string>> user_map;
static HMODULE il2cpp_handle = nullptr;
static uint64_t il2cpp_base = 0;
int target1 = 30052;
int target2 = 30101;
int hit_count = 0;



void init_il2cpp_api() {
#define DO_API(r, n, p) n = (r (*) p)GetProcAddress(il2cpp_handle, #n)

#include "il2cpp-api-functions.h"

#undef DO_API
}
using namespace std::literals;

namespace
{

	void create_debug_console()
	{
		AllocConsole();
		FILE* _;
		// open stdout stream
		freopen_s(&_, "CONOUT$", "w", stdout);
		freopen_s(&_, "CONOUT$", "w", stderr);
		freopen_s(&_, "CONIN$", "r", stdin);

		SetConsoleTitle(L"Umapyoi");

		// set this to avoid turn japanese texts into question mark
		//SetConsoleOutputCP(CP_UTF8);
		std::locale::global(std::locale(""));

		const HANDLE handle = CreateFile(L"CONOUT$", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
		                                 NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		DWORD mode;
		if (!GetConsoleMode(handle, &mode))
		{
			std::cout << "GetConsoleMode " << GetLastError() << "\n";
		}
		mode |= ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		if (!SetConsoleMode(handle, mode))
		{
			std::cout << "SetConsoleMode " << GetLastError() << "\n";
		}
	}

	std::string current_time()
	{
		const auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::system_clock::now().time_since_epoch());
		return std::to_string(ms.count());
	}

	void write_file(const std::string& file_name, const char* buffer, const int len)
	{
		FILE* fp;
		fopen_s(&fp, file_name.c_str(), "wb");
		if (fp != nullptr)
		{
			fwrite(buffer, 1, len, fp);
			fclose(fp);
		}
	}

	void read_file(const std::string& file_name, char* buffer, const int len)
	{
		FILE* fp;
		fopen_s(&fp, file_name.c_str(), "rb");
		if (fp != nullptr)
		{
			fread(buffer, 1, len, fp);
			fclose(fp);
		}
	}


	void transfer_string(const char* str, System_String_o* dst) {
		int len = strlen(str);
		uint16_t* t = new uint16_t[len*2]{};
		for (int i = 0; i < len; i++) {
			t[i] = (uint16_t)str[i];
		}
		memcpy(&(dst->fields.m_firstChar), t, len * 2);
		dst->fields.m_stringLength = len;
	}

	void print_system_string(System_String_o* t) {
		int len = t->fields.m_stringLength;
		uint16_t* str = &(t->fields.m_firstChar);
		for (int i = 0; i < len; ++i)
		{
			printf("%c", str[i]);
		}
		printf("\n");
	}


	bool loop_ready = 1;
	bool gacha_ready = 1;
	int current_user = 0;
	int fcoin = 0;
	int first_time_gacha = 1;

	const Il2CppClass* GachaExecRequest_klass = nullptr;
	void* gacha_ptr_orig = nullptr;
	void* gacha_ptr = nullptr;
	void gacha_ptr_hook(
		Gallop_GachaExecutor_o* __this,
		System_Action_GachaExecResponse__o* onSuccess,
		void* onError,
		void* method
	)
	{
		printf("[%d]抽卡, %d抽\n", current_user, __this->fields._request->fields.draw_num);
		//__this->fields._request->klass = nullptr;
		reinterpret_cast<decltype(gacha_ptr_hook)*>(gacha_ptr_orig)(
			__this,
			onSuccess,
			onError,
			method
			);
		
	}


	void* present_list_ptr_orig = nullptr;
	void* present_list_ptr = nullptr;



	Il2CppObject* present_list_m_target = nullptr;
	intptr_t present_list_method;
	intptr_t present_list_method_ptr;
	const Il2CppClass* present_klass = nullptr;
	void present_list_ptr_hook(
		int32_t filterLimit,
		Gallop_PresentListBase_FilterCategory_array* categoryArray,
		bool isTimeAsc,
		int32_t offset,
		System_Action_PresentIndexResponse__o* callback,
		void* method
	)
	{
		//std::cout << "hook present_list_ptr_hook" << std::endl;
		reinterpret_cast<decltype(present_list_ptr_hook)*>(present_list_ptr_orig)(
			filterLimit,
			categoryArray,
			isTimeAsc,
			offset,
			callback,
			method
			);
	}

	void* MakeMd5_ptr_orig = nullptr;
	void* MakeMd5_ptr = nullptr;
	System_String_o* MakeMd5_ptr_hook(
		System_String_o* input,
		void* method
	)
	{

		std::cout << "hook MakeMd5_ptr_hook" << std::endl;
		printf("md5 input is:");
		print_system_string(input);
		System_String_o* res = reinterpret_cast<decltype(MakeMd5_ptr_hook)*>(MakeMd5_ptr_orig)(
			input,
			method
			);
		printf("md5 outout is:");
		print_system_string(res);

		return res;
	}




	void* receive_all_orig = nullptr;
	void* receive_all_ptr = nullptr;
	void OnClickRecieveAll_hook(
		Gallop_PresentList_o* __this,
		int32_t filterLimit, 
		Gallop_PresentListBase_FilterCategory_array* categoryArray, 
		bool isTimeAsc, 
		void* callback, 
		void* method
	) 
	{
		/*__this->fields._categoryArray->max_length = 0;
		std::cout << __this->fields._categoryArray->m_Items[0] << std::endl;
		std::cout << __this->fields._categoryArray->m_Items[1] << std::endl;
		std::cout << __this->fields._categoryArray->m_Items[2] << std::endl;
		std::cout << __this->fields._categoryArray->max_length << std::endl;
		std::cout << __this->fields._isTimeAsc << std::endl;*/
		__this = new Gallop_PresentList_o;
		__this->fields._confirmPresentList = new System_Collections_Generic_List_PartsPresentListItemBase_Info__o;
		__this->fields._confirmPresentList->fields._size = 1;
		__this->fields._isTimeAsc = true;
		__this->fields._limit = 0;
		__this->fields._categoryArray = new Gallop_PresentListBase_FilterCategory_array;
		__this->fields._categoryArray->max_length = 0;
		__this->fields._categoryArray->m_Items[0] = 0;
		std::cout << "hook OnClickRecieveAll_hook" << std::endl;
		reinterpret_cast<decltype(OnClickRecieveAll_hook)*>(receive_all_orig)(
			__this,
			__this->fields._limit,
			__this->fields._categoryArray,
			__this->fields._isTimeAsc,
			nullptr,
			nullptr
			);

	}

	void* CompressRequest_orig = nullptr;
	void* CompressRequest = nullptr;
	System_Byte_array* CompressRequest_hook(
		System_Byte_array* requestData,
		void* method
	)
	{
		printf("hook CompressRequest_hook\n");
		for (size_t i = 0; i < requestData->max_length; i++)
		{
			printf("%x", requestData->m_Items[i]);
		}
		printf("\n");


		System_Byte_array* res = reinterpret_cast<decltype(CompressRequest_hook)*>(CompressRequest_orig)(
			requestData,
			method
			);

		//for (size_t i = 0; i < res->max_length; i++)
		//{
		//	std::cout << res->m_Items[i];
		//}
		//printf("\n");
		return res;
	}


	void* FromBase64String_orig = nullptr;
	void* FromBase64String = nullptr;
	System_Byte_array* FromBase64String_hook(
		System_String_o* s,
		void* method
	)
	{
		printf("hook FromBase64String_hook\n");
		print_system_string(s);
		System_Byte_array* res = reinterpret_cast<decltype(FromBase64String_hook)*>(FromBase64String_orig)(
			s,
			method
			);
		for (size_t i = 0; i < res->max_length; i++)
		{
			printf("%c", res->m_Items[i]);
		}
		printf("\n");

		return res;
	}


	void* GenRandomBytes_orig = nullptr;
	void* GenRandomBytes = nullptr;
	System_Byte_array* GenRandomBytes_hook(
		int32_t len,
		void* method
	)
	{
		printf("hook GenRandomBytes_hook\n");
		System_Byte_array* res = reinterpret_cast<decltype(GenRandomBytes_hook)*>(GenRandomBytes_orig)(
			len,
			method
			);
		for (size_t i = 0; i < res->max_length; i++)
		{
			printf("%c", res->m_Items[i]);
		}
		printf("\n");

		return res;
	}

	void* Hex2bin_orig = nullptr;
	void* Hex2bin = nullptr;
	System_Byte_array* Hex2bin_hook(
		System_String_o* hex,
		void* method
	)
	{
		printf("hook Hex2bin_hook\n");
		print_system_string(hex);
		System_Byte_array* res = reinterpret_cast<decltype(Hex2bin_hook)*>(Hex2bin_orig)(
			hex,
			method
			);
		for (size_t i = 0; i < res->max_length; i++)
		{
			printf("%c", res->m_Items[i]);
		}
		printf("\n");

		return res;
	}


	void* CommonHeader_orig = nullptr;
	void* CommonHeader = nullptr;
	System_Byte_array* CommonHeader_hook(
		void* method
	)
	{
		printf("hook CommonHeader_hook\n");
		System_Byte_array* res = reinterpret_cast<decltype(CommonHeader_hook)*>(CommonHeader_orig)(
			method
			);
		for (size_t i = 0; i < res->max_length; i++)
		{
			printf("%02x", res->m_Items[i]);
		}
		printf("\n");

		return res;
	}

	void* Post_orig = nullptr;
	void* Post = nullptr;
	bool Post_hook(
		void* __this,
		System_String_o* url,
		System_Byte_array* postData,
		System_Collections_Generic_Dictionary_string__string__o* headers,
		void* method
	)
	{
		System_String_o* t = (System_String_o*)il2cpp_string_new("https://api-umamusume.cygames.jp/umamusume/tool/start_session");
		printf("hook Post_hook\n");
		print_system_string(url);
		printf("%d\n", postData->max_length);
		for (size_t i = 0; i < postData->max_length; i++)
		{
			std::cout << postData->m_Items[i];
		}
		printf("\n");
		bool res = reinterpret_cast<decltype(Post_hook)*>(Post_orig)(
			__this,
			url,
			postData,
			headers,
			method
			);
		return res;
	}


	void* Decompress_orig = nullptr;
	void* Decompress = nullptr;
	System_Byte_array* Decompress_hook(
		System_Byte_array* compressed,
		void* method
	)
	{
		//compressed->bounds = nullptr;

		printf("hook Decompress_hook\n");
		for (size_t i = 0; i < compressed->max_length; i++)
		{
			std::cout << compressed->m_Items[i];
		}
		printf("\n");
		System_Byte_array* res = reinterpret_cast<decltype(Decompress_hook)*>(Decompress_orig)(
			compressed,
			method
			);
		for (size_t i = 0; i < res->max_length; i++)
		{
			std::cout << res->m_Items[i];
		}
		printf("\n");
		return res;
	}



	void* start_session_orig = nullptr;
	void* start_session = nullptr;
	bool start_session_hook(
		Gallop_MainGameInitializer__StartSession_d__21_o* __this,
		void* method
	)
	{
		//print_system_string(value);
		//printf("next currentis %p, state is %d\n",__this->fields.__2__current, __this->fields.__1__state);

		bool res =  reinterpret_cast<decltype(start_session_hook)*>(start_session_orig)(
			__this,
			method
			);
		//printf("next currentis %p, state is %d\n", __this->fields.__2__current, __this->fields.__1__state);
		return res;
	}

	void* ToolStartSessionTask_orig = nullptr;
	void* ToolStartSessionTask = nullptr;
	void ToolStartSessionTask_hook(
		Gallop_ToolStartSessionTask_o* __this,
		Gallop_ToolStartSessionRequest_o* request,
		void* onSuccess,
		void* onError,
		void* method
	)
	{

		printf("hook ToolStartSessionTask\n");
		reinterpret_cast<decltype(ToolStartSessionTask_hook)*>(ToolStartSessionTask_orig)(
			__this,
			request,
			onSuccess,
			onError,
			method
			);

		
	}

	void* CreateSingletonFromPrefab_orig = nullptr;
	void* CreateSingletonFromPrefab = nullptr;
	void CreateSingletonFromPrefab_hook(
		System_String_o* path,
		void* method
	)
	{

		printf("hook CreateSingletonFromPrefab\n");
		print_system_string(path);
		reinterpret_cast<decltype(CreateSingletonFromPrefab_hook)*>(CreateSingletonFromPrefab_orig)(
			path,
			method
			);
	}

	void* MoveNext_orig = nullptr;
	void* MoveNext = nullptr;
	Gallop_GameSystem_o* gamesystem = nullptr;
	bool MoveNext_hook(
		Gallop_GameSystem__InitializeGame_d__33_o* __this,
		void* method
	)
	{
		//print_system_string(value);
		gamesystem = __this->fields.__4__this;
		printf("before hook MoveNext_hook, state is %d %d %p\n", __this->fields.__1__state, __this->fields._i_5__2, __this->fields.__4__this);
		int before = __this->fields.__1__state;
		bool res = reinterpret_cast<decltype(MoveNext_hook)*>(MoveNext_orig)(
			__this,
			method
			);

#ifdef LOOP
		if (__this->fields.__1__state == -1121) {
			std::cout << "账号登录" << std::endl;
			Gallop_MainGameInitializer__StartSession_d__21_o* t = new Gallop_MainGameInitializer__StartSession_d__21_o;
			t->fields.__1__state = 0;
			t->fields.__2__current = 0;
			start_session_hook(t, nullptr);
			
			//return 0;
	}
#endif // LOOP


		printf("after hook MoveNext_hook, state is %d %d \n", __this->fields.__1__state, __this->fields._i_5__2);
		return res;
	}

	void* GenerateUdid_orig = nullptr;
	void* GenerateUdid = nullptr;
	void GenerateUdid_hook(
		bool force,
		void* method
	)
	{
		//print_system_string(value);
		printf("hook GenerateUdid_hook\n");
		reinterpret_cast<decltype(GenerateUdid_hook)*>(GenerateUdid_orig)(
			force,
			method
			);
	}

	void* DecompressResponse_orig = nullptr;
	void* DecompressResponse = nullptr;
	System_Byte_array* DecompressResponse_hook(
		System_Byte_array* responseData,
		const MethodInfo* method
	)
	{
		System_Byte_array* t = new System_Byte_array;
		t->max_length = responseData->max_length;

		printf("hook DecompressResponse_hook %d\n", responseData->max_length);
		for (size_t i = 0; i < responseData->max_length; i++)
		{
			std::cout << responseData->m_Items[i];
			t->m_Items[i] = responseData->m_Items[i];
		}
		printf("\n");
		System_Byte_array* res =  reinterpret_cast<decltype(DecompressResponse_hook)*>(DecompressResponse_orig)(
			t,
			method
			);

		for (size_t i = 0; i < res->max_length; i++)
		{
			std::cout << res->m_Items[i];
		}
		printf("\n");

		return res;
	}

	void* data_transition_ptr_orig = nullptr;
	void* data_transition_ptr = nullptr;
	void data_transition_ptr_hook(
		int64_t viewerId,
		System_String_o* password,
		System_Action_DataLinkChainByTransitionCodeResponse__o* onSuccess,
		void* method
	)
	{
		//std::cout << "hook data_transition_ptr_hook" << std::endl;
		reinterpret_cast<decltype(data_transition_ptr_hook)*>(data_transition_ptr_orig)(
			viewerId,
			password,
			onSuccess,
			method
			);
	}

	void* UpdateCoin_orig = nullptr;
	void* UpdateCoin = nullptr;
	void UpdateCoin_hook(
		void* __this,
		Gallop_CoinInfo_o* coinInfo,
		void* method
	)
	{
		printf("大撒大撒\n");
		//printf("[%d]解析抽卡结果\n", current_user);
		//fcoin = response->fields.data->fields.coin_info->fields.fcoin;
		//printf("[%d]剩余钻石数量：%d\n", current_user, fcoin);
		//gacha_ready = 1;
		reinterpret_cast<decltype(UpdateCoin_hook)*>(UpdateCoin_orig)(
			__this,
			coinInfo,
			method
			);
	}

	void loop_gacha();
	int present_num = 0;
	void* onLoginSuccess_orig = nullptr;
	void* onLoginSuccess = nullptr;
	void onLoginSuccess_hook(
		Gallop_LoginResponse_o* response,
		void* onLoginFinish,
		void* method
	)
	{
		fcoin = response->fields.data->fields.coin_info->fields.fcoin;
		present_num = response->fields.data->fields.menu_badge_info->fields.present_num;
		printf("[%d]当前钻石数量：%d\n", current_user, fcoin);
		printf("[%d]当前礼物数量：%d\n", current_user, present_num);
		std::thread(loop_gacha).detach();
		reinterpret_cast<decltype(onLoginSuccess_hook)*>(onLoginSuccess_orig)(
			response,
			onLoginFinish,
			method
			);
	}

	void* Login_orig = nullptr;
	void* Login = nullptr;
	void Login_hook(
		void* manager,
		void* onLoginFinish,
		void* method
	)
	{
		//std::cout << "hook Login_hook" << std::endl;
		reinterpret_cast<decltype(Login_hook)*>(Login_orig)(
			nullptr,
			onLoginFinish,
			method
			);
	}

	void* SaveNewUser_ptr_orig = nullptr;
	void* SaveNewUser_ptr = nullptr;
	void SaveNewUser_ptr_hook(
		int64_t newViewerId,
		System_String_o* newName,
		System_String_o* newAuthKey,
		void* method
	)
	{
		//std::cout << "hook SaveNewUser_ptr_hook" << std::endl;
		reinterpret_cast<decltype(SaveNewUser_ptr_hook)*>(SaveNewUser_ptr_orig)(
			newViewerId,
			newName,
			newAuthKey,
			method
			);
	}

	bool is_login_rsp = false;
	int current_viewer_id = 0;
	void* UpdateSessionID_ptr_orig = nullptr;
	void* UpdateSessionID_ptr = nullptr;
	void UpdateSessionID_ptr_hook(
		System_String_o* response,
		void* method
	)
	{
		
		//std::cout << "hook UpdateSessionID_ptr_hook" << std::endl;
		//print_system_string(response);
		//Il2CppString* t = il2cpp_string_new("aoligeigei");
		if (is_login_rsp) {
			//printf("is login set initial session id\n");
			std::string concact = std::to_string(current_viewer_id) + "3b991a0b-a972-4977-a60f-9332eb82f418";
			Il2CppString* t1 = il2cpp_string_new(concact.c_str());
			reinterpret_cast<decltype(UpdateSessionID_ptr_hook)*>(UpdateSessionID_ptr_orig)(
				(System_String_o*)t1,
				method
				);
			is_login_rsp = false;
		}
		else {
			reinterpret_cast<decltype(UpdateSessionID_ptr_hook)*>(UpdateSessionID_ptr_orig)(
				response,
				method
				);
		}

	}

	void* return_title_orig = nullptr;
	void* return_title = nullptr;
	void return_title_hook(
		void* __this,
		//void* res,
		void* method
	)
	{
		std::cout << "hook return_title" << std::endl;
		//print_system_string(response);
		//Il2CppString* t = il2cpp_string_new("aoligeigei");
		reinterpret_cast<decltype(return_title_hook)*>(return_title_orig)(
			__this,
			//res,
			method
			);
	}

	Gallop_SaveDataManager_c* save_Data_klass = nullptr;

	void* presentlist_success_ptr_orig = nullptr;
	void* presentlist_success_ptr = nullptr;
	void presentlist_success_ptr_hook(
		void* __this,
		void* res,
		void* method
	)
	{
		printf("hook presentlist_success_ptr_hook\n");
		reinterpret_cast<decltype(presentlist_success_ptr_hook)*>(presentlist_success_ptr_orig)(
			__this,
			res,
			method
			);
	}

	void* LZ4_decompress_safe_ext_orig = nullptr;




	int LZ4_decompress_safe_ext_hook(
		char* src,
		char* dst,
		int compressedSize,
		int dstCapacity)
	{
		
		const int ret = reinterpret_cast<decltype(LZ4_decompress_safe_ext_hook)*>(LZ4_decompress_safe_ext_orig)(
			src, dst, compressedSize, dstCapacity);
		if (config::get().save_response)
		{
			const auto out_path = std::string("CarrotJuicer\\").append(current_time()).append("R.msgpack");
			write_file(out_path, dst, ret);
			//std::cout << "wrote response to " << out_path << "\n";
		}

		std::string response = dst;
		std::string err;

		msgpack11::MsgPack des_msgpack = msgpack11::MsgPack::parse(dst, err);
#ifdef LOOP
		if (des_msgpack["data"]["resource_version"].string_value().length() > 0) {
			printf("[%d]账号登录成功\n", current_user);

			Gallop_PresentListBase_FilterCategory_array* t = new Gallop_PresentListBase_FilterCategory_array;
			t->max_length = 1;
			t->m_Items[0] = 0;
			printf("[%d]开始获取用户信息\n", current_user);
			Login_hook(nullptr, nullptr, nullptr);
			//present_list_ptr_hook(0, t, true, 0, nullptr, nullptr);
			//OnClickRecieveAll_hook(nullptr, 0, nullptr, 0, nullptr, nullptr);

		}
		else if (des_msgpack["response_code"].int32_value() == 523 || des_msgpack["response_code"].int32_value() == 700) {
			printf("[%d]账号密码错误，或者当前账号已经登录\n", current_user);
			//return_title_hook(nullptr, nullptr);
			loop_ready = 1;
		}
		else if (des_msgpack["data"]["chained_user_name"].string_value().length() > 0) {
			int chained_viewer_id = des_msgpack["data"]["chained_viewer_id"].int32_value();
			printf("[%d]账号切换成功\n", current_user);
			std::string chained_user_name = des_msgpack["data"]["chained_user_name"].string_value();
			std::string auth_key = des_msgpack["data"]["auth_key"].string_value();

			user_map[chained_viewer_id]["user_name"] = chained_user_name;
			user_map[chained_viewer_id]["auth_key"] = auth_key;

			Il2CppString* name = il2cpp_string_new(chained_user_name.c_str());
			Il2CppString* auth_keyy = il2cpp_string_new(auth_key.c_str());
			printf("[%d]保存当前账号信息\n", current_user);
			SaveNewUser_ptr_hook(chained_viewer_id, (System_String_o*)(name), (System_String_o*)auth_keyy, nullptr);
			is_login_rsp = true;
			current_viewer_id = chained_viewer_id;
			//GenerateUdid_hook(true, nullptr);

			
			Gallop_MainGameInitializer__StartSession_d__21_o* t = new Gallop_MainGameInitializer__StartSession_d__21_o;
			t->fields.__1__state = 0;
			t->fields.__2__current = 0;
			printf("[%d]账号登录\n", current_user);
			start_session_hook(t, nullptr);
		}


		else if (des_msgpack["response_code"].int32_value() == 1805) {
			printf("[%d]首抽免费已经使用，跳过\n", current_user);
			//return_title_hook(nullptr, nullptr);
			gacha_ready = 1;
		}
		else if (des_msgpack["response_code"].int32_value() == 208) {
			printf("[%d]请求过快跳过\n", current_user);
			//return_title_hook(nullptr, nullptr);
			gacha_ready = 1;
		}
		for (int i = 0; i + 6 < dstCapacity; ++i) {
			if (dst[i] == 'p' && dst[i+1] == 'i' && dst[i + 2] == 'e' && dst[i+3] == 'c' && dst[i+4] == 'e' && dst[i+5] == '_' && dst[i+6] == 'i') {
				unsigned char t[] = { unsigned char(dst[i - 2]) , unsigned char(dst[i - 3]) };
				short receive = *((unsigned short*)t);
				if (receive == target1) {
					hit_count++;
					printf("[%d]抽中新卡，当前抽中次数：%d\n", current_user, hit_count);
				}
				
			}
		}
		if (!first_time_gacha) {
			for (int i = dstCapacity; i > 0; --i) {
				if (dst[i - 4] == 'f' && dst[i - 3] == 'c' && dst[i - 2] == 'o' && dst[i - 1] == 'i' && dst[i] == 'n') {
					if (unsigned char(dst[i + 1]) == 204) {
						fcoin = unsigned char(dst[i + 2]);
					}
					else if (unsigned char(dst[i + 1]) == 205) {
						unsigned char t[] = { unsigned char(dst[i + 3]) , unsigned char(dst[i + 2]) };
						unsigned short test = *((unsigned short*)t);
						fcoin = test;
					}
					else if (unsigned char(dst[i + 1]) == 206) {
						unsigned char t[] = { unsigned char(dst[i + 5]),unsigned char(dst[i + 4]),unsigned char(dst[i + 3]) , unsigned char(dst[i + 2]) };
						fcoin = *((int*)t);
					}
					else if (unsigned char(dst[i + 1]) != 0) {
						fcoin = unsigned char(dst[i + 1]);
					}
					printf("[%d]剩余钻石数量：%d\n", current_user, fcoin);
					gacha_ready = 1;
					break;
				}

			}
		}
#endif // LOOP

		if (des_msgpack["data_headers"]["sid"].string_value().length() > 0) {
			std::string sid = des_msgpack["data_headers"]["sid"].string_value();
			int viewer_id = des_msgpack["data_headers"]["viewer_id"].int32_value();
			user_map[viewer_id]["sid"] = sid;
		}


		
		return ret;
	}

	void* LZ4_compress_default_ext_orig = nullptr;

	int LZ4_compress_default_ext_hook(
		char* src,
		char* dst,
		int srcSize,
		int dstCapacity)
	{
#ifdef LOOP
		//int pos = 0;
		//for (int i = 160; i < srcSize; ++i) {
		//	if (src[i] == 'n' && src[i + 1] == 'u' && src[i + 2] == 'm' && src[i + 5] == 'v') {
		//		pos = i + 3;
		//		src[pos] = present_num;
		//		break;
		//	}
		//}
#endif // LOOP


		
		//std::cout << "hook LZ4_compress_default_ext_hook" << std::endl;
		const int ret = reinterpret_cast<decltype(LZ4_compress_default_ext_hook)*>(LZ4_compress_default_ext_orig)(
			src, dst, srcSize, dstCapacity);

		if (config::get().save_request)
		{
			const auto out_path = std::string("CarrotJuicer\\").append(current_time()).append("Q.msgpack");
			write_file(out_path, src, srcSize);
			//const auto out_path2 = std::string("CarrotJuicer\\").append(current_time()).append("afterQ.msgpack");
			//write_file(out_path2, dst, dstCapacity);
			//std::cout << "wrote request to " << out_path << "\n";
		}

		//if (config::get().print_request)
		//{
		//	const std::string data(src, srcSize);
		//	requests::print_request_additional_info(data);
		//}

		return ret;
	}

	std::string NumberToString(int x) {
		std::stringstream ss;
		ss << x;
		return ss.str();
	}

	void loop_gacha() {
		FILE* fp;
		fopen_s(&fp, "./res.txt", "a+");
		auto domain = il2cpp_domain_get();
		il2cpp_thread_attach(domain);
		Sleep(1000);
		while (fcoin > 150 * 10) {
			if (hit_count == 5) {
				printf("[%d]满破，停止抽卡\n", current_user);
				break;
			}
			if (gacha_ready) {
				Gallop_GachaExecutor_o* __this = new Gallop_GachaExecutor_o;
				__this->fields._request = new Gallop_GachaExecRequest_o;
				__this->fields._IsExecutable_k__BackingField = true;
				__this->fields._IsCostShortage_k__BackingField = false;
				__this->fields._request->klass = (Gallop_GachaExecRequest_c*)GachaExecRequest_klass;
				__this->fields._request->fields.gacha_id = 30111;
				__this->fields._request->fields.draw_type = 1;
				__this->fields._request->fields.draw_num = 10;
				__this->fields._request->fields.current_num = fcoin;
				__this->fields._request->fields.current_stock_num = 0;
				__this->fields._request->fields.item_id = 0;
				gacha_ready = 0;
				if (first_time_gacha) {
					__this->fields._request->fields.current_num = 0;
				}
				first_time_gacha = 0;
				gacha_ptr_hook(__this, nullptr, nullptr, nullptr);
			}
			Sleep(1000);
		}
		std::string t = NumberToString(current_user) + "抽中新卡：" + NumberToString(hit_count) + "\n";
		fputs(t.c_str(), fp);
		fclose(fp);
		loop_ready = 1;
	}


	void main_menu() {
		FILE* p;
		fopen_s(&p, "./user.txt", "r");
		char* input = new char[100];
		while (!feof(p)) {
			fgets(input, 50, p);
			std::string format = input;
			std::string username = format.substr(0, format.find(" "));
			std::string password = format.substr(format.find(" ") + 1, format.length() - format.find(" ") -2 );
			//format.replace(format.find("密码："), 6, " ");
			//printf("%s", format);
			user_map[std::stoi(username)]["password"] = password;
		}



		char type[100];
		//init_il2cpp_api();
		auto domain = il2cpp_domain_get();
		il2cpp_thread_attach(domain);
		int time = 0;
		while (std::cin >> type) {
			if (strcmp(type, "list") == 0) {
				Gallop_PresentListBase_FilterCategory_array* t = new Gallop_PresentListBase_FilterCategory_array;
				t->max_length = 1;
				t->m_Items[0] = 0;
				present_list_ptr_hook(0, t,true,0,nullptr,nullptr);
			}
			else if (strcmp(type, "gacha") == 0) {
				loop_gacha();
			}
			else if (strcmp(type, "receive") == 0) {
				OnClickRecieveAll_hook(nullptr, 0, nullptr, 0, nullptr, nullptr);
			}
			else if (strcmp(type, "map") == 0) {
				for (auto user = user_map.begin(); user != user_map.end(); user++) {
					int id = user->first;
					std::cout << id << " " << user->second["password"] <<user->second["user_name"] << " " << user->second["auth_key"] << " " << user->second["sid"] << std::endl;
				}
			}
			else if (strcmp(type, "start") == 0) {

				//Il2CppString* t1 = il2cpp_string_new("61382259989bc9284-2aad-4370-be25-cf8635f9e0be");
				//UpdateSessionID_ptr_hook((System_String_o*)t1, nullptr);

				Gallop_MainGameInitializer__StartSession_d__21_o* t = new Gallop_MainGameInitializer__StartSession_d__21_o;
				t->fields.__1__state = 0;
				t->fields.__2__current = 0;
				start_session_hook(t, nullptr);
			}
			else if (strcmp(type, "setnew") == 0) {
				int username;
				char iname[500]{};
				char ikey[500]{};
				std::cin >> username;
				std::cin >> iname;
				std::cin >> ikey;
				Il2CppString* name = il2cpp_string_new(iname);
				Il2CppString* auth_keyy = il2cpp_string_new(ikey);
				SaveNewUser_ptr_hook(username, (System_String_o*)name, (System_String_o*)auth_keyy, nullptr);
				//UpdateHomeBadgeInfo_hook(t, nullptr);
				return_title_hook(nullptr, nullptr);
				//return_title_hook(username, nullptr);
			}
			else if (strcmp(type, "login") == 0) {
				//UpdateHomeBadgeInfo_hook(nullptr, nullptr, nullptr);

				if (time == 1) {
					int username = 613235182;
					Il2CppString* pass = il2cpp_string_new("WZfapq3717");
					data_transition_ptr_hook(username, (System_String_o*)pass, nullptr, nullptr);
				}
				else {
					int username = 613822599;
					Il2CppString* pass = il2cpp_string_new("AZwrzx0989");
					data_transition_ptr_hook(username, (System_String_o*)pass, nullptr, nullptr);
				}
				time = !time;
				
			}
			else if (strcmp(type, "setsid") == 0) {
				char sid[500]{};
				std::cin >> sid;
				Il2CppString* t = il2cpp_string_new(sid);
				UpdateSessionID_ptr_hook((System_String_o*)t, nullptr);
			}
			else if (strcmp(type, "data") == 0) {
				System_String_o* password = new System_String_o;
				int username;
				char str[100]{};
				std::cin >> username;
				std::cin >> str;
				//const char* str = "AXeqfu6757";
				int len = strlen(str);
				uint16_t* t = new uint16_t[len]{};
				for (int i = 0; i < len; i++) {
					t[i] = (uint16_t)str[i];
				}
				memcpy(&(password->fields.m_firstChar), t, len * 2);
				password->fields.m_stringLength = len;
				data_transition_ptr_hook(username, password, nullptr, nullptr);
			}
			else if (strcmp(type, "base64") == 0) {
				
				std::string in;
				std::cin >> in;
				//std::string out = base64_decode(in);
				//char* test = new char[919]{};
				System_Byte_array* t = new System_Byte_array;
				t->max_length = in.length();
				for (int i = 0; i < in.length(); ++i) {
					t->m_Items[i] = in[i];
				}
				DecompressResponse_hook(t, nullptr);

			}
			else if (strcmp(type, "msgpack") == 0) {
				char test[1000];
				const auto out_path = std::string("CarrotJuicer\\").append("1659617997414").append("Q.msgpack");
				//const auto out_path = std::string("CarrotJuicer\\").append("1659615015625").append("R.msgpack");

				read_file(out_path, test, 1000);
				std::string err;
				char t[1000];
				int offset;
				for (int i = 160; i < 175; ++i) {
					if (test[i] == 0) {
						offset = i - 1;
						break;
					}
				}
				int pos = 0;
				for (int i = 160; i < 1000; ++i) {
					if (test[i] == 'n' && test[i+1] == 'u' && test[i+2] == 'm' && test[i + 5] == 'v') {
						pos = i + 3;
						break;
					}
				}
				test[pos] = 10;
				printf("%d %c\n", offset, test[offset]);
				for (size_t i = offset; i < 1000; i++)
				{
					t[i - offset] = test[i];
				}
				msgpack11::MsgPack des_msgpack = msgpack11::MsgPack::parse(t,1000, err);
				std::cout << des_msgpack["current_rest_present_num"].int32_value();

			}
			else if (strcmp(type, "dump") == 0) {
				HMODULE ga = GetModuleHandle(L"GameAssembly.dll");
				if (ga != nullptr) {
					//PEGetProcAddress(ga);
					pedump(ga, "dumped_GameAssembly.dll");
				}
			}
			else if (strcmp(type, "loop") == 0) {
				auto iter = user_map.begin();
				printf("开始抽卡\n");
				while (1) {
					if (iter == user_map.end()) {
						printf("所有账号抽取结束\n");
						break;
					}
					if (loop_ready) {
						Il2CppString* password = il2cpp_string_new(iter->second["password"].c_str());
						int viewer_id = iter->first;
						current_user = viewer_id;
						printf("\n[%d]当前抽取账号：%d，密码：%s\n", current_user, viewer_id, iter->second["password"].c_str());
						printf("[%d]开始切换账号\n", current_user);
						data_transition_ptr_hook(viewer_id, (System_String_o*)password, nullptr, nullptr);
						iter++;
						hit_count = 0;
						loop_ready = 0;
						gacha_ready = 1;
					}
				}
			}
			else if (strcmp(type, "test") == 0) {
				//char test[1000]{};
				//char dst[3000]{};
				//const auto in_path = std::string("CarrotJuicer\\").append("1659866797588").append("Q.msgpack");
				//read_file(in_path, test, 999);

				//LZ4_compress_default_ext_hook(test,dst,520, 3000);

				//const auto out_path = std::string("CarrotJuicer\\").append("1659866797588").append("Qaoligei.msgpack");
				//write_file(out_path, test, 999);
				char req[1000]{0xa6};

				const auto out_path = std::string("CarrotJuicer\\").append("test_req").append(".msgpack");
				write_file(out_path, req, 999);










			}
			else {
				System_String_o* input = new System_String_o;
				const char* str = type;
				int len = strlen(str);
				uint16_t* t = new uint16_t[len]{};
				for (int i = 0; i < len; i++) {
					t[i] = (uint16_t)str[i];
				}
				memcpy(&(input->fields.m_firstChar), t, len*2);
				input->fields.m_stringLength = len;
				//MakeMd5_ptr_hook(input, nullptr);


			}
		}
	}

	void bootstrap_carrot_juicer()
	{

		std::filesystem::create_directory("CarrotJuicer");

		const auto libnative_module = GetModuleHandle(L"libnative.dll");
		printf("libnative.dll at %p\n", libnative_module);

		const auto GameAssembly = GetModuleHandle(L"GameAssembly.dll");
		printf("GameAssembly.dll at %p\n", GameAssembly);


		il2cpp_handle = GameAssembly;
		init_il2cpp_api();
		auto domain = il2cpp_domain_get();
		//Il2CppThread* t = il2cpp_thread_attach(domain);
		size_t size;
		auto assemblies = il2cpp_domain_get_assemblies(domain, &size);

		std::unordered_map<std::string, std::unordered_map<std::string, void*>> hook_map;


		std::cout << "size:" << size << std::endl;
		for (int i = 0; i < size; ++i) {
			auto image = il2cpp_assembly_get_image(assemblies[i]);
			if (strcmp(il2cpp_image_get_name(image),"Cute.Http.Assembly.dll") == 0) {
				auto classCount = il2cpp_image_get_class_count(image);
				for (int j = 0; j < classCount; ++j) {
					const Il2CppClass* klass = il2cpp_image_get_class(image, j);
					auto type = il2cpp_class_get_type(const_cast<Il2CppClass*>(klass));
					std::string name = il2cpp_type_get_name(type);
					if (strcmp(il2cpp_type_get_name(type), "Cute.Http.WWWRequest") == 0) {
						auto method = il2cpp_class_get_method_from_name((Il2CppClass*)klass, "Post", 3);
						Post = method->methodPointer;
					}
				}

			}
			else if (strcmp(il2cpp_image_get_name(image), "umamusume.dll") == 0) {
				auto classCount = il2cpp_image_get_class_count(image);
				for (int j = 0; j < classCount; ++j) {
					const Il2CppClass* klass = il2cpp_image_get_class(image, j);
					//printf("aoligei %p %s\n", klass, klass->name);
					auto type = il2cpp_class_get_type(const_cast<Il2CppClass*>(klass));
					std::string name = il2cpp_type_get_name(type);
					if (strcmp(il2cpp_type_get_name(type), "Gallop.PresentList") == 0) {
						auto method = il2cpp_class_get_method_from_name((Il2CppClass*)klass, "APIPresentReceiveAll", 4);			
						receive_all_ptr = method->methodPointer;
						auto method2 = il2cpp_class_get_method_from_name((Il2CppClass*)klass, "APIPresentIndex", 5);
						present_list_ptr = method2->methodPointer;
					}
					else if (strcmp(il2cpp_type_get_name(type), "Gallop.GachaExecutor") == 0) {
						auto method = il2cpp_class_get_method_from_name((Il2CppClass*)klass, "Execute", 2);
						gacha_ptr = method->methodPointer;
					}
					else if (strcmp(il2cpp_type_get_name(type), "Gallop.MainGameInitializer.<StartSession>d__21") == 0) {
						auto method3 = il2cpp_class_get_method_from_name((Il2CppClass*)klass, "MoveNext", 0);
						start_session = method3->methodPointer;
					}
				
					else if (strcmp(il2cpp_type_get_name(type), "Gallop.DataTransition") == 0) {
						auto method = il2cpp_class_get_method_from_name((Il2CppClass*)klass, "APIExecDataTransition", 3);
						data_transition_ptr = method->methodPointer;

						auto method2 = il2cpp_class_get_method_from_name((Il2CppClass*)klass, "ReturnTitle", 0);
						return_title = method2->methodPointer;

						auto method3 = il2cpp_class_get_method_from_name((Il2CppClass*)klass, "SaveNewUser", 3);
						SaveNewUser_ptr = method3->methodPointer;
					}
					else if (strcmp(il2cpp_type_get_name(type), "Gallop.Cryptographer") == 0) {
						auto method = il2cpp_class_get_method_from_name((Il2CppClass*)klass, "MakeMd5", 1);
						MakeMd5_ptr = method->methodPointer;


					}
					else if (strcmp(il2cpp_type_get_name(type), "Gallop.PresentList.<>c__DisplayClass11_0") == 0) {
						auto method = il2cpp_class_get_method_from_name((Il2CppClass*)klass, "<APIIndex>b__0",1);
						presentlist_success_ptr = method->methodPointer;
					}
					else if (strcmp(il2cpp_type_get_name(type), "Gallop.Certification") == 0) {
						auto method = il2cpp_class_get_method_from_name((Il2CppClass*)klass, "set_SessionId", 1);
						UpdateSessionID_ptr = method->methodPointer;

						auto method2 = il2cpp_class_get_method_from_name((Il2CppClass*)klass, "GenerateUdid", 1);
						GenerateUdid = method2->methodPointer;
					}
					else if (strcmp(il2cpp_type_get_name(type), "Gallop.GameSystem.<InitializeGame>d__33") == 0) {
						auto method = il2cpp_class_get_method_from_name((Il2CppClass*)klass, "MoveNext", 0);
						MoveNext = method->methodPointer;
					}
					else if (strcmp(il2cpp_type_get_name(type), "Gallop.GameSystem") == 0) {
						auto method = il2cpp_class_get_method_from_name((Il2CppClass*)klass, "CreateSingletonFromPrefab", 1);
						CreateSingletonFromPrefab = method->methodPointer;
					}
					else if (strcmp(il2cpp_type_get_name(type), "Gallop.HttpHelper") == 0) {
						auto method = il2cpp_class_get_method_from_name((Il2CppClass*)klass, "CompressRequest", 1);
						CompressRequest = method->methodPointer;

						auto method2 = il2cpp_class_get_method_from_name((Il2CppClass*)klass, "DecompressResponse", 1);
						DecompressResponse = method2->methodPointer;

						auto method3 = il2cpp_class_get_method_from_name((Il2CppClass*)klass, "Login", 2);
						Login = method3->methodPointer;

						auto method4 = il2cpp_class_get_method_from_name((Il2CppClass*)klass, "onLoginSuccess", 2);
						onLoginSuccess = method4->methodPointer;
					}
					else if (strcmp(il2cpp_type_get_name(type), "Gallop.GallopUtil") == 0) {
						auto method = il2cpp_class_get_method_from_name((Il2CppClass*)klass, "Hex2bin", 1);
						Hex2bin = method->methodPointer;

						auto method2 = il2cpp_class_get_method_from_name((Il2CppClass*)klass, "GenRandomBytes", 1);
						GenRandomBytes = method2->methodPointer;
					}
					else if (strcmp(il2cpp_type_get_name(type), "Gallop.WorkUserData") == 0) {
						auto method = il2cpp_class_get_method_from_name((Il2CppClass*)klass, "UpdateCoin", 1);
						UpdateCoin = method->methodPointer;
					}

				}

			}
			else if (strcmp(il2cpp_image_get_name(image), "umamusume.Http.dll") == 0) {
				auto classCount = il2cpp_image_get_class_count(image);
				for (int j = 0; j < classCount; ++j) {
					const Il2CppClass* klass = il2cpp_image_get_class(image, j);
					if (strcmp(klass->name, "GachaExecRequest") == 0) {
						GachaExecRequest_klass = klass;
					}
					auto type = il2cpp_class_get_type(const_cast<Il2CppClass*>(klass));
					if (strcmp(il2cpp_type_get_name(type), "Gallop.ToolStartSessionTask") == 0) {	
						//void* iter = nullptr;
						//while (auto method = il2cpp_class_get_methods((Il2CppClass*)klass, &iter)) {
						//	std::cout << method->name << std::endl;
						//}
						auto method = il2cpp_class_get_method_from_name((Il2CppClass*)klass, ".ctor", 3);
						ToolStartSessionTask = method->methodPointer;
					}

				}
			}
			else if (strcmp(il2cpp_image_get_name(image), "LibNative.Runtime.dll") == 0) {
				auto classCount = il2cpp_image_get_class_count(image);
				for (int j = 0; j < classCount; ++j) {
					const Il2CppClass* klass = il2cpp_image_get_class(image, j);
					auto type = il2cpp_class_get_type(const_cast<Il2CppClass*>(klass));
					if (strcmp(il2cpp_type_get_name(type), "LibNative.LZ4.SimpleLZ4Frame") == 0) {

						auto method = il2cpp_class_get_method_from_name((Il2CppClass*)klass, "Decompress", 1);
						Decompress = method->methodPointer;
					} else if (strcmp(il2cpp_type_get_name(type), "LibNative.Network") == 0) {

						auto method = il2cpp_class_get_method_from_name((Il2CppClass*)klass, "CommonHeader", 0);
						CommonHeader = method->methodPointer;
					}

				}
			}
			else if (strcmp(il2cpp_image_get_name(image), "mscorlib.dll") == 0) {
				auto classCount = il2cpp_image_get_class_count(image);
				for (int j = 0; j < classCount; ++j) {
					const Il2CppClass* klass = il2cpp_image_get_class(image, j);
					auto type = il2cpp_class_get_type(const_cast<Il2CppClass*>(klass));
					if (strcmp(il2cpp_type_get_name(type), "System.Convert") == 0) {
						auto method = il2cpp_class_get_method_from_name((Il2CppClass*)klass, "FromBase64String", 1);
						FromBase64String = method->methodPointer;
					}
				}
			}
		}

		//printf("Decompress at %p\n", Decompress);
		//if (Decompress == nullptr)
		//{
		//	return;
		//}
		//MH_CreateHook(Decompress, Decompress_hook, &Decompress_orig);
		//MH_EnableHook(Decompress);


		//printf("FromBase64String at %p\n", FromBase64String);
		//if (FromBase64String == nullptr)
		//{
		//	return;
		//}
		//MH_CreateHook(FromBase64String, FromBase64String_hook, &FromBase64String_orig);
		//MH_EnableHook(FromBase64String);

		//printf("GenRandomBytes at %p\n", GenRandomBytes);
		//if (GenRandomBytes == nullptr)
		//{
		//	return;
		//}
		//MH_CreateHook(GenRandomBytes, GenRandomBytes_hook, &GenRandomBytes_orig);
		//MH_EnableHook(GenRandomBytes);

		//printf("Hex2bin at %p\n", Hex2bin);
		//if (Hex2bin == nullptr)
		//{
		//	return;
		//}
		//MH_CreateHook(Hex2bin, Hex2bin_hook, &Hex2bin_orig);
		//MH_EnableHook(Hex2bin);

		//printf("CommonHeader at %p\n", CommonHeader);
		//if (CommonHeader == nullptr)
		//{
		//	return;
		//}
		//MH_CreateHook(CommonHeader, CommonHeader_hook, &CommonHeader_orig);
		//MH_EnableHook(CommonHeader);

		//printf("CompressRequest at %p\n", CompressRequest);
		//if (CompressRequest == nullptr)
		//{
		//	return;
		//}
		//MH_CreateHook(CompressRequest, CompressRequest_hook, &CompressRequest_orig);
		//MH_EnableHook(CompressRequest);

		//printf("Post at %p\n", Post);
		//if (Post == nullptr)
		//{
		//	return;
		//}
		//MH_CreateHook(Post, Post_hook, &Post_orig);
		//MH_EnableHook(Post);

		//printf("ToolStartSessionTask at %p\n", ToolStartSessionTask);
		//if (ToolStartSessionTask == nullptr)
		//{
		//	return;
		//}
		//MH_CreateHook(ToolStartSessionTask, ToolStartSessionTask_hook, &ToolStartSessionTask_orig);
		//MH_EnableHook(ToolStartSessionTask);

		//printf("DecompressResponse at %p\n", DecompressResponse);
		//if (start_session == nullptr)
		//{
		//	return;
		//}
		//MH_CreateHook(DecompressResponse, DecompressResponse_hook, &DecompressResponse_orig);
		//MH_EnableHook(DecompressResponse);

		//printf("GenerateUdid at %p\n", GenerateUdid);
		//if (start_session == nullptr)
		//{
		//	return;
		//}
		//MH_CreateHook(GenerateUdid, GenerateUdid_hook, &GenerateUdid_orig);
		//MH_EnableHook(GenerateUdid);

		//printf("CreateSingletonFromPrefab at %p\n", CreateSingletonFromPrefab);
		//if (start_session == nullptr)
		//{
		//	return;
		//}
		//MH_CreateHook(CreateSingletonFromPrefab, CreateSingletonFromPrefab_hook, &CreateSingletonFromPrefab_orig);
		//MH_EnableHook(CreateSingletonFromPrefab);

		printf("UpdateCoin at %p\n", UpdateCoin);
		if (UpdateCoin == nullptr)
		{
			return;
		}
		MH_CreateHook(UpdateCoin, UpdateCoin_hook, &UpdateCoin);
		MH_EnableHook(UpdateCoin);

		printf("onLoginSuccess at %p\n", onLoginSuccess);
		if (onLoginSuccess == nullptr)
		{
			return;
		}
		MH_CreateHook(onLoginSuccess, onLoginSuccess_hook, &onLoginSuccess_orig);
		MH_EnableHook(onLoginSuccess);

		printf("Login at %p\n", Login);
		if (Login == nullptr)
		{
			return;
		}
		MH_CreateHook(Login, Login_hook, &Login_orig);
		MH_EnableHook(Login);

		//printf("MoveNext at %p\n", MoveNext);
		//if (start_session == nullptr)
		//{
		//	return;
		//}
		//MH_CreateHook(MoveNext, MoveNext_hook, &MoveNext_orig);
		//MH_EnableHook(MoveNext);

		//printf("return_title at %p\n", return_title);
		//if (start_session == nullptr)
		//{
		//	return;
		//}
		//MH_CreateHook(return_title, return_title_hook, &return_title_orig);
		//MH_EnableHook(return_title);

		printf("UpdateSessionID_ptr at %p\n", UpdateSessionID_ptr);
		if (start_session == nullptr)
		{
			return;
		}
		MH_CreateHook(UpdateSessionID_ptr, UpdateSessionID_ptr_hook, &UpdateSessionID_ptr_orig);
		MH_EnableHook(UpdateSessionID_ptr);

		printf("start_session at %p\n", start_session);
		if (start_session == nullptr)
		{
			return;
		}
		MH_CreateHook(start_session, start_session_hook, &start_session_orig);
		MH_EnableHook(start_session);

		printf("gacha_ptr at %p\n", gacha_ptr);
		if (gacha_ptr == nullptr)
		{
			return;
		}
		MH_CreateHook(gacha_ptr, gacha_ptr_hook, &gacha_ptr_orig);
		MH_EnableHook(gacha_ptr);

		printf("receive_all at %p\n", receive_all_ptr);
		if (receive_all_ptr == nullptr)
		{
			return;
		}
		MH_CreateHook(receive_all_ptr, OnClickRecieveAll_hook, &receive_all_orig);
		MH_EnableHook(receive_all_ptr);


		const auto LZ4_decompress_safe_ext_ptr = GetProcAddress(libnative_module, "LZ4_decompress_safe_ext");
		printf("LZ4_decompress_safe_ext at %p\n", LZ4_decompress_safe_ext_ptr);
		if (LZ4_decompress_safe_ext_ptr == nullptr)
		{
			return;
		}
		MH_CreateHook(LZ4_decompress_safe_ext_ptr, LZ4_decompress_safe_ext_hook, &LZ4_decompress_safe_ext_orig);
		MH_EnableHook(LZ4_decompress_safe_ext_ptr);

		const auto LZ4_compress_default_ext_ptr = GetProcAddress(libnative_module, "LZ4_compress_default_ext");
		printf("LZ4_compress_default_ext at %p\n", LZ4_compress_default_ext_ptr);
		if (LZ4_compress_default_ext_ptr == nullptr)
		{
			return;
		}
		MH_CreateHook(LZ4_compress_default_ext_ptr, LZ4_compress_default_ext_hook, &LZ4_compress_default_ext_orig);
		MH_EnableHook(LZ4_compress_default_ext_ptr);

		//printf("MakeMd5_ptr at %p\n", MakeMd5_ptr);
		//if (MakeMd5_ptr == nullptr)
		//{
		//	return;
		//}
		//MH_CreateHook(MakeMd5_ptr, MakeMd5_ptr_hook, &MakeMd5_ptr_orig);
		//MH_EnableHook(MakeMd5_ptr);

		printf("present_list_ptr at %p\n", present_list_ptr);
		if (present_list_ptr == nullptr)
		{
			return;
		}
		MH_CreateHook(present_list_ptr, present_list_ptr_hook, &present_list_ptr_orig);
		MH_EnableHook(present_list_ptr);

		printf("SaveNewUser_ptr at %p\n", SaveNewUser_ptr);
		if (SaveNewUser_ptr == nullptr)
		{
			return;
		}
		MH_CreateHook(SaveNewUser_ptr, SaveNewUser_ptr_hook, &SaveNewUser_ptr_orig);
		MH_EnableHook(SaveNewUser_ptr);

		
		printf("data_transition_ptr at %p\n", data_transition_ptr);
		if (data_transition_ptr == nullptr)
		{
			return;
		}
		MH_CreateHook(data_transition_ptr, data_transition_ptr_hook, &data_transition_ptr_orig);
		MH_EnableHook(data_transition_ptr);
	}

	void* load_library_w_orig = nullptr;

	HMODULE __stdcall load_library_w_hook(const wchar_t* path)
	{
		printf("Saw %ls\n", path);

		// GameAssembly.dll code must be loaded and decrypted while loading criware library
		if (path == L"cri_ware_unity.dll"s)
		{
			HMODULE ga = GetModuleHandle(L"libnative.dll");
			if (ga != nullptr) {
				//PEGetProcAddress(ga);
				pedump(ga, "dumped_libnative.dll");
			}

			bootstrap_carrot_juicer();

			MH_DisableHook(LoadLibraryW);
			MH_RemoveHook(LoadLibraryW);
			std::thread(main_menu).detach();
			return LoadLibraryW(path);
		}

		return reinterpret_cast<decltype(LoadLibraryW)*>(load_library_w_orig)(path);
	}
}

void attach()
{
	create_debug_console();
	if (MH_Initialize() != MH_OK)
	{
		printf("Failed to initialize MinHook.\n");
		return;
	}
	printf("MinHook initialized.\n");

	MH_CreateHook(LoadLibraryW, load_library_w_hook, &load_library_w_orig);
	MH_EnableHook(LoadLibraryW);

	config::load();

	std::thread(edb::init).detach();
	std::thread(notifier::init).detach();
}

void detach()
{
	MH_DisableHook(MH_ALL_HOOKS);
	MH_Uninitialize();
}
