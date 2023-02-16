// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include<Windows.h>
#include<TlHelp32.h>
#include<iostream>
#include "functions.h"
#include <fstream>
#include <codecvt> 
#include<vector>
#include<exception>
using namespace std;
void InitAPI() {
	g_free = (G_FREE)GetProcAddress(hMono, "g_free");

	if (!g_free)
		g_free = (G_FREE)GetProcAddress(hMono, "mono_unity_g_free");


	mono_free = (MONO_FREE)GetProcAddress(hMono, "mono_free");

	mono_get_root_domain = (MONO_GET_ROOT_DOMAIN)GetProcAddress(hMono, "mono_get_root_domain");
	mono_thread_attach = (MONO_THREAD_ATTACH)GetProcAddress(hMono, "mono_thread_attach");
	mono_thread_detach = (MONO_THREAD_DETACH)GetProcAddress(hMono, "mono_thread_detach");
	mono_thread_cleanup = (MONO_THREAD_CLEANUP)GetProcAddress(hMono, "mono_thread_cleanup");

	mono_object_get_class = (MONO_OBJECT_GET_CLASS)GetProcAddress(hMono, "mono_object_get_class");

	mono_domain_foreach = (MONO_DOMAIN_FOREACH)GetProcAddress(hMono, "mono_domain_foreach");
	mono_domain_set = (MONO_DOMAIN_SET)GetProcAddress(hMono, "mono_domain_set");
	mono_domain_get = (MONO_DOMAIN_GET)GetProcAddress(hMono, "mono_domain_get");
	mono_assembly_foreach = (MONO_ASSEMBLY_FOREACH)GetProcAddress(hMono, "mono_assembly_foreach");
	mono_assembly_get_image = (MONO_ASSEMBLY_GET_IMAGE)GetProcAddress(hMono, "mono_assembly_get_image");
	mono_image_get_assembly = (MONO_IMAGE_GET_ASSEMBLY)GetProcAddress(hMono, "mono_image_get_assembly");

	mono_image_get_name = (MONO_IMAGE_GET_NAME)GetProcAddress(hMono, "mono_image_get_name");
	mono_image_get_filename = (MONO_IMAGE_GET_FILENAME)GetProcAddress(hMono, "mono_image_get_filename");

	mono_image_get_table_info = (MONO_IMAGE_GET_TABLE_INFO)GetProcAddress(hMono, "mono_image_get_table_info");
	mono_image_rva_map = (MONO_IMAGE_RVA_MAP)GetProcAddress(hMono, "mono_image_rva_map");

	mono_table_info_get_rows = (MONO_TABLE_INFO_GET_ROWS)GetProcAddress(hMono, "mono_table_info_get_rows");
	mono_metadata_decode_row_col = (MONO_METADATA_DECODE_ROW_COL)GetProcAddress(hMono, "mono_metadata_decode_row_col");
	mono_metadata_string_heap = (MONO_METADATA_STRING_HEAP)GetProcAddress(hMono, "mono_metadata_string_heap");


	mono_class_get = (MONO_CLASS_GET)GetProcAddress(hMono, "mono_class_get");
	mono_class_from_typeref = (MONO_CLASS_FROM_TYPEREF)GetProcAddress(hMono, "mono_class_from_typeref");
	mono_class_name_from_token = (MONO_CLASS_NAME_FROM_TOKEN)GetProcAddress(hMono, "mono_class_name_from_token");
	mono_class_from_name_case = (MONO_CLASS_FROM_NAME_CASE)GetProcAddress(hMono, "mono_class_from_name_case");
	mono_class_from_name = (MONO_CLASS_FROM_NAME_CASE)GetProcAddress(hMono, "mono_class_from_name");
	mono_class_get_name = (MONO_CLASS_GET_NAME)GetProcAddress(hMono, "mono_class_get_name");
	mono_class_get_namespace = (MONO_CLASS_GET_NAMESPACE)GetProcAddress(hMono, "mono_class_get_namespace");
	mono_class_get_methods = (MONO_CLASS_GET_METHODS)GetProcAddress(hMono, "mono_class_get_methods");
	mono_class_get_method_from_name = (MONO_CLASS_GET_METHOD_FROM_NAME)GetProcAddress(hMono, "mono_class_get_method_from_name");
	mono_class_get_fields = (MONO_CLASS_GET_FIELDS)GetProcAddress(hMono, "mono_class_get_fields");
	mono_class_get_parent = (MONO_CLASS_GET_PARENT)GetProcAddress(hMono, "mono_class_get_parent");
	mono_class_get_image = (MONO_CLASS_GET_IMAGE)GetProcAddress(hMono, "mono_class_get_image");
	mono_class_is_generic = (MONO_CLASS_IS_GENERIC)GetProcAddress(hMono, "mono_class_is_generic");
	mono_class_vtable = (MONO_CLASS_VTABLE)GetProcAddress(hMono, "mono_class_vtable");
	mono_class_from_mono_type = (MONO_CLASS_FROM_MONO_TYPE)GetProcAddress(hMono, "mono_class_from_mono_type");
	mono_class_get_element_class = (MONO_CLASS_GET_ELEMENT_CLASS)GetProcAddress(hMono, "mono_class_get_element_class");
	mono_class_instance_size = (MONO_CLASS_INSTANCE_SIZE)GetProcAddress(hMono, "mono_class_instance_size");

	mono_class_num_fields = (MONO_CLASS_NUM_FIELDS)GetProcAddress(hMono, "mono_class_num_fields");
	mono_class_num_methods = (MONO_CLASS_NUM_METHODS)GetProcAddress(hMono, "mono_class_num_methods");


	mono_field_get_name = (MONO_FIELD_GET_NAME)GetProcAddress(hMono, "mono_field_get_name");
	mono_field_get_type = (MONO_FIELD_GET_TYPE)GetProcAddress(hMono, "mono_field_get_type");
	mono_field_get_parent = (MONO_FIELD_GET_PARENT)GetProcAddress(hMono, "mono_field_get_parent");
	mono_field_get_offset = (MONO_FIELD_GET_OFFSET)GetProcAddress(hMono, "mono_field_get_offset");
	mono_field_get_flags = (MONO_FIELD_GET_FLAGS)GetProcAddress(hMono, "mono_field_get_flags");

	mono_type_get_name = (MONO_TYPE_GET_NAME)GetProcAddress(hMono, "mono_type_get_name");
	mono_type_get_type = (MONO_TYPE_GET_TYPE)GetProcAddress(hMono, "mono_type_get_type");
	mono_type_get_name_full = (MONO_TYPE_GET_NAME_FULL)GetProcAddress(hMono, "mono_type_get_name_full");

	mono_method_get_name = (MONO_METHOD_GET_NAME)GetProcAddress(hMono, "mono_method_get_name");
	mono_method_get_class = (MONO_METHOD_GET_CLASS)GetProcAddress(hMono, "mono_method_get_class");
	mono_method_get_header = (MONO_METHOD_GET_HEADER)GetProcAddress(hMono, "mono_method_get_header");
	mono_method_get_flags = (MONO_METHOD_GET_FLAGS)GetProcAddress(hMono, "mono_method_get_flags");
	mono_method_signature = (MONO_METHOD_SIG)GetProcAddress(hMono, "mono_method_signature");
	mono_method_get_param_names = (MONO_METHOD_GET_PARAM_NAMES)GetProcAddress(hMono, "mono_method_get_param_names");



	mono_signature_get_desc = (MONO_SIGNATURE_GET_DESC)GetProcAddress(hMono, "mono_signature_get_desc");
	mono_signature_get_params = (MONO_SIGNATURE_GET_PARAMS)GetProcAddress(hMono, "mono_signature_get_params");
	mono_signature_get_param_count = (MONO_SIGNATURE_GET_PARAM_COUNT)GetProcAddress(hMono, "mono_signature_get_param_count");
	mono_signature_get_return_type = (MONO_SIGNATURE_GET_RETURN_TYPE)GetProcAddress(hMono, "mono_signature_get_return_type");



	mono_compile_method = (MONO_COMPILE_METHOD)GetProcAddress(hMono, "mono_compile_method");
	mono_free_method = (MONO_FREE_METHOD)GetProcAddress(hMono, "mono_free_method");
	mono_jit_info_table_find = (MONO_JIT_INFO_TABLE_FIND)GetProcAddress(hMono, "mono_jit_info_table_find");
	mono_jit_info_get_method = (MONO_JIT_INFO_GET_METHOD)GetProcAddress(hMono, "mono_jit_info_get_method");
	mono_jit_info_get_code_start = (MONO_JIT_INFO_GET_CODE_START)GetProcAddress(hMono, "mono_jit_info_get_code_start");
	mono_jit_info_get_code_size = (MONO_JIT_INFO_GET_CODE_SIZE)GetProcAddress(hMono, "mono_jit_info_get_code_size");
	mono_jit_exec = (MONO_JIT_EXEC)GetProcAddress(hMono, "mono_jit_exec");

	mono_method_header_get_code = (MONO_METHOD_HEADER_GET_CODE)GetProcAddress(hMono, "mono_method_header_get_code");
	mono_disasm_code = (MONO_DISASM_CODE)GetProcAddress(hMono, "mono_disasm_code");

	mono_vtable_get_static_field_data = (MONO_VTABLE_GET_STATIC_FIELD_DATA)GetProcAddress(hMono, "mono_vtable_get_static_field_data");

	mono_method_desc_new = (MONO_METHOD_DESC_NEW)GetProcAddress(hMono, "mono_method_desc_new");;
	mono_method_desc_from_method = (MONO_METHOD_DESC_FROM_METHOD)GetProcAddress(hMono, "mono_method_desc_from_method");;
	mono_method_desc_free = (MONO_METHOD_DESC_FREE)GetProcAddress(hMono, "mono_method_desc_free");;

	mono_string_new = (MONO_STRING_NEW)GetProcAddress(hMono, "mono_string_new");
	mono_string_to_utf8 = (MONO_STRING_TO_UTF8)GetProcAddress(hMono, "mono_string_to_utf8");
	mono_array_new = (MONO_ARRAY_NEW)GetProcAddress(hMono, "mono_array_new");
	mono_value_box = (MONO_VALUE_BOX)GetProcAddress(hMono, "mono_value_box");
	mono_object_unbox = (MONO_OBJECT_UNBOX)GetProcAddress(hMono, "mono_object_unbox");
	mono_object_new = (MONO_OBJECT_NEW)GetProcAddress(hMono, "mono_object_new");

	mono_class_get_type = (MONO_CLASS_GET_TYPE)GetProcAddress(hMono, "mono_class_get_type");
	mono_class_get_nesting_type = (MONO_CLASS_GET_NESTING_TYPE)GetProcAddress(hMono, "mono_class_get_nesting_type");

	mono_method_desc_search_in_image = (MONO_METHOD_DESC_SEARCH_IN_IMAGE)GetProcAddress(hMono, "mono_method_desc_search_in_image");
	mono_runtime_invoke = (MONO_RUNTIME_INVOKE)GetProcAddress(hMono, "mono_runtime_invoke");
	mono_runtime_object_init = (MONO_RUNTIME_OBJECT_INIT)GetProcAddress(hMono, "mono_runtime_object_init");
	mono_assembly_name_new = (MONO_ASSEMBLY_NAME_NEW)GetProcAddress(hMono, "mono_assembly_name_new");
	mono_assembly_loaded = (MONO_ASSEMBLY_LOADED)GetProcAddress(hMono, "mono_assembly_loaded");
	mono_assembly_open = (MONO_ASSEMBLY_OPEN)GetProcAddress(hMono, "mono_assembly_open");
	mono_image_open = (MONO_IMAGE_OPEN)GetProcAddress(hMono, "mono_image_open");
	mono_field_static_get_value = (MONO_FIELD_STATIC_GET_VALUE)GetProcAddress(hMono, "mono_field_static_get_value");
	mono_field_static_set_value = (MONO_FIELD_STATIC_SET_VALUE)GetProcAddress(hMono, "mono_field_static_set_value");
	mono_runtime_is_shutting_down = (MONO_RUNTIME_IS_SHUTTING_DOWN)GetProcAddress(hMono, "mono_runtime_is_shutting_down");
}
void _cdecl AssemblyEnumerator(void* domain, vector<UINT64>* v)
{
	v->push_back((UINT_PTR)domain);
}
WORD UTF8TOUTF16(char* szUtf8) {
#if (_WINDOWS && (_MSC_VER <= 1916))
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> convert;

	try {
		std::wstring dest = convert.from_bytes(szUtf8);
		return *(WORD*)&dest[0];
	}
	catch (const std::range_error&) {
		return NULL;
	}
#else
	std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
	std::u16string dest = convert.from_bytes(szUtf8);
	return *(WORD*)&dest[0];
#endif
}
void dumpsdk() {
	HANDLE ths = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, GetCurrentProcessId());
	void *Base;
	if (ths != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32 me;
		me.dwSize = sizeof(me);

		if (Module32First(ths, &me))
		{
			do
			{
				if (GetProcAddress(me.hModule, "mono_thread_attach"))
				{
					Base = me.modBaseAddr;
					wprintf_s(L"MODULE：%s\n", me.szExePath);
					hMono = me.hModule;
					break;
				}

			} while (Module32Next(ths, &me));

		}
		CloseHandle(ths);
	}
	InitAPI();
	cout << "API init down" << endl;
	int status;
	if (!mono_get_root_domain) {
		printf("API init error\n");
		return;
	}
	void* domain = (void*)mono_get_root_domain();
	void* mono_selfthread = mono_thread_attach(domain);
	vector<UINT64>v;
	mono_assembly_foreach((GFunc)AssemblyEnumerator, &v);
	printf("module count:%d\n", v.size());
	for (auto assembly : v) {
		
		void *image = mono_assembly_get_image((void *)assembly);
		char* s = mono_image_get_name(image);
		printf("module name: %s\n", s);
		void* tdef = mono_image_get_table_info(image, MONO_TABLE_TYPEDEF);
		if (tdef) {//遍历类
			std::string ClassName;
			int tdefcount = mono_table_info_get_rows(tdef);
			for (int i = 0; i < tdefcount; i++) {
				void* c = mono_class_get(image, MONO_TOKEN_TYPE_DEF | (i + 1));
				if (c) {
					//printf("c:%p\n", c);
					void* iter = NULL;
					void* field = NULL;
					char* name = mono_class_get_name(c);
					char* type;
					std::string sName = std::string(name);
					if ((BYTE)name[0] == 0xEE) {
						char szUeName[32];
						sprintf_s(szUeName, 32, "\\u%04X", UTF8TOUTF16(name));
						sName = szUeName;
					}
					ClassName = sName;
					cout << "\tclass name: " << ClassName<< endl;
					name = mono_class_get_namespace(c);
					cout << "\t\t" << "field:" << endl;
					do {//遍历属性
						field = mono_class_get_fields(c, &iter);
						std::string FieldName;
						if (field) {
							void* fieldtype = mono_field_get_type(field);
							name = mono_field_get_name(field);
							type = mono_type_get_name(fieldtype);
							std::string sName = std::string(name);
							std::string sType = std::string(type);
							if ((BYTE)name[0] == 0xEE) {
								char szUeName[32];
								sprintf_s(szUeName, 32, "\\u%04X", UTF8TOUTF16(name));
								sName = szUeName;
							}
							FieldName = sName;
							if ((BYTE)type[0] == 0xEE) {
								char szUeName[32];
								sprintf_s(szUeName, 32, "\\u%04X", UTF8TOUTF16(type));
								sType = szUeName;
							}
							cout << "\t\t\t" << sType << " " << ClassName << "::" << FieldName << ";" << endl;
						}
					} while (field);
					void* method=NULL;
					iter = NULL;
					cout << "\t\t" << "method:" << endl;
					do {//遍历方法
						std::string MethodName;
						method = mono_class_get_methods(c, &iter);
						//printf("method: %p\n", method);
						if (method) {
							printf("\t\t\t0x%p: ", method);
							uint32_t flags;
							name = mono_method_get_name(method);
							flags = mono_method_get_flags(method, NULL);
							
							std::string sName = std::string(name);
							if ((BYTE)name[0] == 0xEE) {
								char szUeName[32];
								sprintf_s(szUeName, 32, "\\u%04X", UTF8TOUTF16(name));
								sName = szUeName;
							}
							MethodName = sName;
							void* methodsignature = mono_method_signature(method);
							if (methodsignature) {
								MonoType* returntype = mono_signature_get_return_type(methodsignature);
								char* returntypename = mono_type_get_name(returntype);
								int paramcount = mono_signature_get_param_count(methodsignature);
								char** names = (char**)calloc(sizeof(char*), paramcount);
								printf("\t%s ",returntypename);
								cout << ClassName << "::" << MethodName << "(";
								//printf("\t\t\t\tnames:%p\n", names);
								mono_method_get_param_names(method, (const char**)names);
								for (int j = 0; j <  paramcount; j++) { 
									gpointer ITER = NULL;
									MonoType* paramtype;
									
									paramtype = mono_signature_get_params((MonoMethodSignature*)methodsignature, &ITER);
									if (paramtype) {
										void* type = mono_class_from_mono_type(paramtype);
										char* TypeName;
										TypeName = mono_class_get_name(type);
										printf("%s ", TypeName);
										printf("%s", names[j]);
										if (j != paramcount - 1) {
											putchar(',');
										}
									}
									
								}

								cout << ");"<<endl;
								
							}
						}
					} while (method);
				}
			}
		}
	}
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
	case DLL_PROCESS_ATTACH: {
#ifdef DEBUG
		AllocConsole();
		freopen("CONOUT$", "w", stdout);
		dumpsdk();
		system("pause");
#else // DEBUG
		freopen("D:\\SDK.txt", "wb+", stdout);
		ios::sync_with_stdio(0);
		//streambuf* coutBuf = cout.rdbuf();			// 保存cout流缓冲区指针
		//ofstream OF("D:\\SDK.txt");
		//streambuf* fileBuf = OF
		// .rdbuf();			// 获取文件out.txt流缓冲区指针
		//cout.rdbuf(fileBuf);
		//Sleep(2000);
		__try {
			dumpsdk();
		}
		__finally {
			printf("error\n");
			//Sleep(10000);
		}
		//MessageBoxA(NULL, "SDK Dump Success!", "Info", MB_OK);
#endif
	}
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

