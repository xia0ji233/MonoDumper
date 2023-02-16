#pragma once
#include <windows.h>
#include<stdint.h>
#define MONOCMD_INITMONO 0
#define MONOCMD_OBJECT_GETCLASS 1
#define MONOCMD_ENUMDOMAINS 2
#define MONOCMD_SETCURRENTDOMAIN 3
#define MONOCMD_ENUMASSEMBLIES 4
#define MONOCMD_GETIMAGEFROMASSEMBLY 5
#define MONOCMD_GETIMAGENAME 6
#define MONOCMD_ENUMCLASSESINIMAGE 7
#define MONOCMD_ENUMFIELDSINCLASS 8
#define MONOCMD_ENUMMETHODSINCLASS 9
#define MONOCMD_COMPILEMETHOD 10

#define MONOCMD_GETMETHODHEADER 11
#define MONOCMD_GETMETHODHEADER_CODE 12
#define MONOCMD_LOOKUPRVA 13
#define MONOCMD_GETJITINFO 14
#define MONOCMD_FINDCLASS 15
#define MONOCMD_FINDMETHOD 16
#define MONOCMD_GETMETHODNAME 17
#define MONOCMD_GETMETHODCLASS 18
#define MONOCMD_GETCLASSNAME 19
#define MONOCMD_GETCLASSNAMESPACE 20
#define MONOCMD_FREEMETHOD 21
#define MONOCMD_TERMINATE 22
#define MONOCMD_DISASSEMBLE 23
#define MONOCMD_GETMETHODSIGNATURE 24
#define MONOCMD_GETPARENTCLASS 25
#define MONOCMD_GETSTATICFIELDADDRESSFROMCLASS 26
#define MONOCMD_GETTYPECLASS 27
#define MONOCMD_GETARRAYELEMENTCLASS 28
#define MONOCMD_FINDMETHODBYDESC 29
#define MONOCMD_INVOKEMETHOD 30
#define MONOCMD_LOADASSEMBLY 31
#define MONOCMD_GETFULLTYPENAME 32
#define MONOCMD_OBJECT_NEW 33
#define MONOCMD_OBJECT_INIT 34
#define MONOCMD_GETVTABLEFROMCLASS 35
#define MONOCMD_GETMETHODPARAMETERS 36
#define MONOCMD_ISCLASSGENERIC 37
#define MONOCMD_ISIL2CPP 38
#define MONOCMD_FILLOPTIONALFUNCTIONLIST 39
#define MONOCMD_GETSTATICFIELDVALUE 40
#define MONOCMD_SETSTATICFIELDVALUE 41
#define MONOCMD_GETCLASSIMAGE 42
#define MONOCMD_FREE 43
#define MONOCMD_GETIMAGEFILENAME 44
#define MONOCMD_GETCLASSNESTINGTYPE 45

typedef struct {} MonoType;
typedef struct {} MonoMethodSignature;
typedef void* gpointer;

typedef void(__cdecl* MonoDomainFunc) (void* domain, void* user_data);
typedef void(__cdecl* GFunc)          (void* data, void* user_data);

typedef void(__cdecl* G_FREE)(void* ptr);

typedef void* (__cdecl* MONO_GET_ROOT_DOMAIN)(void);
typedef void* (__cdecl* MONO_THREAD_ATTACH)(void* domain);
typedef void(__cdecl* MONO_THREAD_DETACH)(void* monothread);
typedef void(__cdecl* MONO_THREAD_CLEANUP)(void);
typedef void* (__cdecl* MONO_OBJECT_GET_CLASS)(void* object);

typedef void(__cdecl* MONO_DOMAIN_FOREACH)(MonoDomainFunc func, void* user_data);

typedef int(__cdecl* MONO_DOMAIN_SET)(void* domain, BOOL force);
typedef void* (__cdecl* MONO_DOMAIN_GET)();
typedef int(__cdecl* MONO_ASSEMBLY_FOREACH)(GFunc func, void* user_data);
typedef void* (__cdecl* MONO_ASSEMBLY_GET_IMAGE)(void* assembly);
typedef void* (__cdecl* MONO_ASSEMBLY_OPEN)(void* fname, int* status);
typedef void* (__cdecl* MONO_IMAGE_GET_ASSEMBLY)(void* image);
typedef char* (__cdecl* MONO_IMAGE_GET_NAME)(void* image);
typedef void* (__cdecl* MONO_IMAGE_OPEN)(const char* fname, int* status);
typedef char* (__cdecl* MONO_IMAGE_GET_FILENAME)(void* image);


typedef void* (__cdecl* MONO_IMAGE_GET_TABLE_INFO)(void* image, int table_id);
typedef int(__cdecl* MONO_TABLE_INFO_GET_ROWS)(void* tableinfo);
typedef int(__cdecl* MONO_METADATA_DECODE_ROW_COL)(void* tableinfo, int idx, unsigned int col);
typedef char* (__cdecl* MONO_METADATA_STRING_HEAP)(void* image, UINT32 index);

typedef void* (__cdecl* MONO_CLASS_FROM_NAME_CASE)(void* image, char* name_space, char* name);
typedef void* (__cdecl* MONO_CLASS_FROM_NAME)(void* image, char* name_space, char* name);
typedef char* (__cdecl* MONO_CLASS_GET_NAME)(void* klass);
typedef char* (__cdecl* MONO_CLASS_GET_NAMESPACE)(void* klass);
typedef void* (__cdecl* MONO_CLASS_GET)(void* image, UINT32 tokenindex);
typedef void* (__cdecl* MONO_CLASS_FROM_TYPEREF)(void* image, UINT32 type_token);
typedef char* (__cdecl* MONO_CLASS_NAME_FROM_TOKEN)(void* image, UINT32 token);


typedef void* (__cdecl* MONO_CLASS_GET_PROPERTIES)(void* klass, void* iter);
typedef void* (__cdecl* MONO_CLASS_GET_METHODS)(void* klass, void* iter);
typedef void* (__cdecl* MONO_CLASS_GET_METHOD_FROM_NAME)(void* klass, char* methodname, int paramcount);
typedef void* (__cdecl* MONO_CLASS_GET_FIELDS)(void* klass, void* iter);
typedef void* (__cdecl* MONO_CLASS_GET_PARENT)(void* klass);
typedef void* (__cdecl* MONO_CLASS_GET_IMAGE)(void* klass);
typedef void* (__cdecl* MONO_CLASS_VTABLE)(void* domain, void* klass);
typedef int(__cdecl* MONO_CLASS_INSTANCE_SIZE)(void* klass);
typedef void* (__cdecl* MONO_CLASS_FROM_MONO_TYPE)(void* type);
typedef void* (__cdecl* MONO_CLASS_GET_ELEMENT_CLASS)(void* klass);
typedef int(__cdecl* MONO_CLASS_IS_GENERIC)(void* klass);



typedef int(__cdecl* MONO_CLASS_NUM_FIELDS)(void* klass);
typedef int(__cdecl* MONO_CLASS_NUM_METHODS)(void* klass);

typedef char* (__cdecl* MONO_FIELD_GET_NAME)(void* field);
typedef void* (__cdecl* MONO_FIELD_GET_TYPE)(void* field);
typedef void* (__cdecl* MONO_FIELD_GET_PARENT)(void* field);
typedef int(__cdecl* MONO_FIELD_GET_OFFSET)(void* field);

typedef char* (__cdecl* MONO_TYPE_GET_NAME)(void* type);
typedef int(__cdecl* MONO_TYPE_GET_TYPE)(void* type);
typedef char* (__cdecl* MONO_TYPE_GET_NAME_FULL)(void* type, int format);
typedef int(__cdecl* MONO_FIELD_GET_FLAGS)(void* type);




typedef char* (__cdecl* MONO_METHOD_GET_NAME)(void* method);
typedef void* (__cdecl* MONO_COMPILE_METHOD)(void* method);
typedef void(__cdecl* MONO_FREE_METHOD)(void* method);

typedef void* (__cdecl* MONO_JIT_INFO_TABLE_FIND)(void* domain, void* addr);

typedef void* (__cdecl* MONO_JIT_INFO_GET_METHOD)(void* jitinfo);
typedef void* (__cdecl* MONO_JIT_INFO_GET_CODE_START)(void* jitinfo);
typedef int(__cdecl* MONO_JIT_INFO_GET_CODE_SIZE)(void* jitinfo);

typedef int(__cdecl* MONO_JIT_EXEC)(void* domain, void* assembly, int argc, char* argv[]);



typedef void* (__cdecl* MONO_METHOD_GET_HEADER)(void* method);
typedef void* (__cdecl* MONO_METHOD_GET_CLASS)(void* method);
typedef void* (__cdecl* MONO_METHOD_SIG)(void* method);
typedef void* (__cdecl* MONO_METHOD_GET_PARAM_NAMES)(void* method, const char** names);

typedef void* (__cdecl* MONO_METHOD_HEADER_GET_CODE)(void* methodheader, UINT32* code_size, UINT32* max_stack);
typedef char* (__cdecl* MONO_DISASM_CODE)(void* dishelper, void* method, void* ip, void* end);

typedef char* (__cdecl* MONO_SIGNATURE_GET_DESC)(void* signature, int include_namespace);
typedef MonoType* (__cdecl* MONO_SIGNATURE_GET_PARAMS)(MonoMethodSignature* sig, gpointer* iter);
typedef int(__cdecl* MONO_SIGNATURE_GET_PARAM_COUNT)(void* signature);
typedef MonoType* (__cdecl* MONO_SIGNATURE_GET_RETURN_TYPE)(void* signature);


typedef void* (__cdecl* MONO_IMAGE_RVA_MAP)(void* image, UINT32 addr);
typedef void* (__cdecl* MONO_VTABLE_GET_STATIC_FIELD_DATA)(void* vtable);


typedef void* (__cdecl* MONO_METHOD_DESC_NEW)(const char* name, int include_namespace);
typedef void* (__cdecl* MONO_METHOD_DESC_FROM_METHOD)(void* method);
typedef void(__cdecl* MONO_METHOD_DESC_FREE)(void* desc);

typedef void* (__cdecl* MONO_ASSEMBLY_NAME_NEW)(const char* name);
typedef void* (__cdecl* MONO_ASSEMBLY_LOADED)(void* aname);
typedef void* (__cdecl* MONO_IMAGE_LOADED)(void* aname);

typedef void* (__cdecl* MONO_STRING_NEW)(void* domain, const char* text);
typedef char* (__cdecl* MONO_STRING_TO_UTF8)(void*);
typedef void* (__cdecl* MONO_ARRAY_NEW)(void* domain, void* eclass, uintptr_t n);
typedef void* (__cdecl* MONO_OBJECT_TO_STRING)(void* object, void** exc);
typedef void* (__cdecl* MONO_OBJECT_NEW)(void* domain, void* klass);


typedef void(__cdecl* MONO_FREE)(void*);

typedef void* (__cdecl* MONO_METHOD_DESC_SEARCH_IN_IMAGE)(void* desc, void* image);
typedef void* (__cdecl* MONO_RUNTIME_INVOKE)(void* method, void* obj, void** params, void** exc);
typedef void* (__cdecl* MONO_RUNTIME_INVOKE_ARRAY)(void* method, void* obj, void* params, void** exc);
typedef void* (__cdecl* MONO_RUNTIME_OBJECT_INIT)(void* object);

typedef void* (__cdecl* MONO_FIELD_STATIC_GET_VALUE)(void* vtable, void* field, void* output);
typedef void* (__cdecl* MONO_FIELD_STATIC_SET_VALUE)(void* vtable, void* field, void* input);

typedef void* (__cdecl* IL2CPP_FIELD_STATIC_GET_VALUE)(void* field, void* output);
typedef void* (__cdecl* IL2CPP_FIELD_STATIC_SET_VALUE)(void* field, void* input);

typedef void* (__cdecl* MONO_VALUE_BOX)(void* domain, void* klass, void* val);
typedef void* (__cdecl* MONO_OBJECT_UNBOX)(void* obj);
typedef void* (__cdecl* MONO_CLASS_GET_TYPE)(void* klass);
typedef void* (__cdecl* MONO_CLASS_GET_NESTING_TYPE)(void* klass);



//il2cpp:
typedef UINT_PTR* (__cdecl* IL2CPP_DOMAIN_GET_ASSEMBLIES)(void* domain, SIZE_T* size);

typedef int(__cdecl* IL2CPP_IMAGE_GET_CLASS_COUNT)(void* image);
typedef void* (__cdecl* IL2CPP_IMAGE_GET_CLASS)(void* image, int index);

typedef char* (__cdecl* IL2CPP_TYPE_GET_NAME)(void* ptype);
typedef char* (__cdecl* IL2CPP_TYPE_GET_ASSEMBLY_QUALIFIED_NAME)(void* ptype);

typedef int(__cdecl* IL2CPP_METHOD_GET_PARAM_COUNT)(void* method);
typedef char* (__cdecl* IL2CPP_METHOD_GET_PARAM_NAME)(void* method, int index);
typedef void* (__cdecl* IL2CPP_METHOD_GET_PARAM)(void* method, int index);
typedef void* (__cdecl* IL2CPP_METHOD_GET_RETURN_TYPE)(void* method);
typedef void* (__cdecl* IL2CPP_CLASS_FROM_TYPE)(void* type);
typedef wchar_t* (__cdecl* IL2CPP_STRING_CHARS)(void* stringobject);

typedef uint32_t(__cdecl* MONO_METHOD_GET_FLAGS)(void* method, uint32_t* iflags);
typedef int(__cdecl* MONO_RUNTIME_IS_SHUTTING_DOWN)(void);




G_FREE g_free;
MONO_GET_ROOT_DOMAIN mono_get_root_domain;
MONO_THREAD_ATTACH mono_thread_attach;
MONO_THREAD_DETACH mono_thread_detach;
MONO_THREAD_CLEANUP mono_thread_cleanup;
MONO_OBJECT_GET_CLASS mono_object_get_class;
MONO_CLASS_GET_NAME mono_class_get_name;
MONO_CLASS_GET_NAMESPACE mono_class_get_namespace;
MONO_CLASS_GET_PROPERTIES mono_class_get_properties;
MONO_CLASS_GET_PARENT mono_class_get_parent;
MONO_CLASS_GET_IMAGE mono_class_get_image;
MONO_CLASS_VTABLE mono_class_vtable;
MONO_CLASS_INSTANCE_SIZE mono_class_instance_size;
MONO_CLASS_FROM_MONO_TYPE mono_class_from_mono_type;
MONO_CLASS_IS_GENERIC mono_class_is_generic;

MONO_DOMAIN_FOREACH mono_domain_foreach;
MONO_DOMAIN_SET mono_domain_set;
MONO_DOMAIN_GET mono_domain_get;
MONO_ASSEMBLY_FOREACH mono_assembly_foreach;
MONO_ASSEMBLY_GET_IMAGE mono_assembly_get_image;
MONO_IMAGE_GET_ASSEMBLY mono_image_get_assembly;
MONO_ASSEMBLY_OPEN mono_assembly_open;

MONO_IMAGE_GET_NAME mono_image_get_name;
MONO_IMAGE_GET_TABLE_INFO mono_image_get_table_info;
MONO_IMAGE_GET_FILENAME mono_image_get_filename;
MONO_IMAGE_RVA_MAP mono_image_rva_map;
MONO_IMAGE_OPEN mono_image_open;
MONO_IMAGE_LOADED mono_image_loaded;

MONO_TABLE_INFO_GET_ROWS mono_table_info_get_rows;
MONO_METADATA_DECODE_ROW_COL mono_metadata_decode_row_col;
MONO_METADATA_STRING_HEAP mono_metadata_string_heap;
MONO_CLASS_GET mono_class_get;
MONO_CLASS_FROM_TYPEREF mono_class_from_typeref;
MONO_CLASS_NAME_FROM_TOKEN mono_class_name_from_token;

MONO_CLASS_FROM_NAME_CASE mono_class_from_name_case;
MONO_CLASS_FROM_NAME mono_class_from_name;

MONO_CLASS_NUM_FIELDS mono_class_num_fields;
MONO_CLASS_GET_FIELDS mono_class_get_fields;

MONO_CLASS_NUM_METHODS mono_class_num_methods;
MONO_CLASS_GET_METHODS mono_class_get_methods;

MONO_CLASS_GET_METHOD_FROM_NAME mono_class_get_method_from_name;
MONO_CLASS_GET_ELEMENT_CLASS mono_class_get_element_class;


MONO_FIELD_GET_NAME mono_field_get_name;
MONO_FIELD_GET_TYPE mono_field_get_type;
MONO_FIELD_GET_PARENT mono_field_get_parent;
MONO_FIELD_GET_OFFSET mono_field_get_offset;

MONO_TYPE_GET_NAME mono_type_get_name;
MONO_TYPE_GET_TYPE mono_type_get_type;
MONO_TYPE_GET_NAME_FULL mono_type_get_name_full;
MONO_FIELD_GET_FLAGS mono_field_get_flags;

MONO_METHOD_GET_NAME mono_method_get_name;
MONO_METHOD_GET_HEADER mono_method_get_header;
MONO_METHOD_GET_CLASS mono_method_get_class;
MONO_METHOD_SIG mono_method_signature;
MONO_METHOD_GET_PARAM_NAMES mono_method_get_param_names;

MONO_SIGNATURE_GET_DESC mono_signature_get_desc;
MONO_SIGNATURE_GET_PARAMS mono_signature_get_params;
MONO_SIGNATURE_GET_PARAM_COUNT mono_signature_get_param_count;
MONO_SIGNATURE_GET_RETURN_TYPE mono_signature_get_return_type;


MONO_COMPILE_METHOD mono_compile_method;
MONO_FREE_METHOD mono_free_method;

MONO_JIT_INFO_TABLE_FIND mono_jit_info_table_find;
MONO_JIT_INFO_GET_METHOD mono_jit_info_get_method;
MONO_JIT_INFO_GET_CODE_START mono_jit_info_get_code_start;
MONO_JIT_INFO_GET_CODE_SIZE mono_jit_info_get_code_size;
MONO_JIT_EXEC mono_jit_exec;

MONO_METHOD_HEADER_GET_CODE mono_method_header_get_code;
MONO_DISASM_CODE mono_disasm_code;

MONO_VTABLE_GET_STATIC_FIELD_DATA mono_vtable_get_static_field_data;

MONO_METHOD_DESC_NEW mono_method_desc_new;
MONO_METHOD_DESC_FROM_METHOD mono_method_desc_from_method;
MONO_METHOD_DESC_FREE mono_method_desc_free;
MONO_ASSEMBLY_NAME_NEW mono_assembly_name_new;
MONO_ASSEMBLY_LOADED mono_assembly_loaded;

MONO_STRING_NEW mono_string_new;
MONO_STRING_TO_UTF8 mono_string_to_utf8;
MONO_ARRAY_NEW mono_array_new;
MONO_OBJECT_TO_STRING mono_object_to_string;
MONO_OBJECT_NEW mono_object_new;
MONO_FREE mono_free;
MONO_VALUE_BOX mono_value_box;
MONO_OBJECT_UNBOX mono_object_unbox;
MONO_CLASS_GET_TYPE mono_class_get_type;
MONO_CLASS_GET_NESTING_TYPE mono_class_get_nesting_type;


MONO_METHOD_DESC_SEARCH_IN_IMAGE mono_method_desc_search_in_image;
MONO_RUNTIME_INVOKE mono_runtime_invoke;
MONO_RUNTIME_OBJECT_INIT mono_runtime_object_init;

MONO_FIELD_STATIC_GET_VALUE mono_field_static_get_value;
MONO_FIELD_STATIC_SET_VALUE mono_field_static_set_value;

//il2cpp
IL2CPP_FIELD_STATIC_GET_VALUE il2cpp_field_static_get_value;
IL2CPP_FIELD_STATIC_SET_VALUE il2cpp_field_static_set_value;

IL2CPP_DOMAIN_GET_ASSEMBLIES il2cpp_domain_get_assemblies;

IL2CPP_IMAGE_GET_CLASS_COUNT il2cpp_image_get_class_count;
IL2CPP_IMAGE_GET_CLASS il2cpp_image_get_class;

IL2CPP_TYPE_GET_NAME il2cpp_type_get_name;
IL2CPP_TYPE_GET_ASSEMBLY_QUALIFIED_NAME il2cpp_type_get_assembly_qualified_name;

IL2CPP_METHOD_GET_PARAM_COUNT il2cpp_method_get_param_count;
IL2CPP_METHOD_GET_PARAM_NAME il2cpp_method_get_param_name;
IL2CPP_METHOD_GET_PARAM il2cpp_method_get_param;
IL2CPP_METHOD_GET_RETURN_TYPE il2cpp_method_get_return_type;
IL2CPP_CLASS_FROM_TYPE il2cpp_class_from_type;
IL2CPP_STRING_CHARS il2cpp_string_chars;
MONO_METHOD_GET_FLAGS mono_method_get_flags;
MONO_RUNTIME_IS_SHUTTING_DOWN mono_runtime_is_shutting_down;


HMODULE hMono = NULL;
typedef enum {
	MONO_TYPE_END = 0x00,       /* End of List */
	MONO_TYPE_VOID = 0x01,
	MONO_TYPE_BOOLEAN = 0x02,
	MONO_TYPE_CHAR = 0x03,
	MONO_TYPE_I1 = 0x04,
	MONO_TYPE_U1 = 0x05,
	MONO_TYPE_I2 = 0x06,
	MONO_TYPE_U2 = 0x07,
	MONO_TYPE_I4 = 0x08,
	MONO_TYPE_U4 = 0x09,
	MONO_TYPE_I8 = 0x0a,
	MONO_TYPE_U8 = 0x0b,
	MONO_TYPE_R4 = 0x0c,
	MONO_TYPE_R8 = 0x0d,
	MONO_TYPE_STRING = 0x0e,
	MONO_TYPE_PTR = 0x0f,       /* arg: <type> token */
	MONO_TYPE_BYREF = 0x10,       /* arg: <type> token */
	MONO_TYPE_VALUETYPE = 0x11,       /* arg: <type> token */
	MONO_TYPE_CLASS = 0x12,       /* arg: <type> token */
	MONO_TYPE_VAR = 0x13,	   /* number */
	MONO_TYPE_ARRAY = 0x14,       /* type, rank, boundsCount, bound1, loCount, lo1 */
	MONO_TYPE_GENERICINST = 0x15,	   /* <type> <type-arg-count> <type-1> \x{2026} <type-n> */
	MONO_TYPE_TYPEDBYREF = 0x16,
	MONO_TYPE_I = 0x18,
	MONO_TYPE_U = 0x19,
	MONO_TYPE_FNPTR = 0x1b,	      /* arg: full method signature */
	MONO_TYPE_OBJECT = 0x1c,
	MONO_TYPE_SZARRAY = 0x1d,       /* 0-based one-dim-array */
	MONO_TYPE_MVAR = 0x1e,       /* number */
	MONO_TYPE_CMOD_REQD = 0x1f,       /* arg: typedef or typeref token */
	MONO_TYPE_CMOD_OPT = 0x20,       /* optional arg: typedef or typref token */
	MONO_TYPE_INTERNAL = 0x21,       /* CLR internal type */

	MONO_TYPE_MODIFIER = 0x40,       /* Or with the following types */
	MONO_TYPE_SENTINEL = 0x41,       /* Sentinel for varargs method signature */
	MONO_TYPE_PINNED = 0x45,       /* Local var that points to pinned object */

	MONO_TYPE_ENUM = 0x55        /* an enumeration */
} MonoTypeEnum;

typedef enum {
	MONO_TABLE_MODULE,
	MONO_TABLE_TYPEREF,
	MONO_TABLE_TYPEDEF,
	MONO_TABLE_FIELD_POINTER,
	MONO_TABLE_FIELD,
	MONO_TABLE_METHOD_POINTER,
	MONO_TABLE_METHOD,
	MONO_TABLE_PARAM_POINTER,
	MONO_TABLE_PARAM,
	MONO_TABLE_INTERFACEIMPL,
	MONO_TABLE_MEMBERREF, /* 0xa */
	MONO_TABLE_CONSTANT,
	MONO_TABLE_CUSTOMATTRIBUTE,
	MONO_TABLE_FIELDMARSHAL,
	MONO_TABLE_DECLSECURITY,
	MONO_TABLE_CLASSLAYOUT,
	MONO_TABLE_FIELDLAYOUT, /* 0x10 */
	MONO_TABLE_STANDALONESIG,
	MONO_TABLE_EVENTMAP,
	MONO_TABLE_EVENT_POINTER,
	MONO_TABLE_EVENT,
	MONO_TABLE_PROPERTYMAP,
	MONO_TABLE_PROPERTY_POINTER,
	MONO_TABLE_PROPERTY,
	MONO_TABLE_METHODSEMANTICS,
	MONO_TABLE_METHODIMPL,
	MONO_TABLE_MODULEREF, /* 0x1a */
	MONO_TABLE_TYPESPEC,
	MONO_TABLE_IMPLMAP,
	MONO_TABLE_FIELDRVA,
	MONO_TABLE_UNUSED6,
	MONO_TABLE_UNUSED7,
	MONO_TABLE_ASSEMBLY, /* 0x20 */
	MONO_TABLE_ASSEMBLYPROCESSOR,
	MONO_TABLE_ASSEMBLYOS,
	MONO_TABLE_ASSEMBLYREF,
	MONO_TABLE_ASSEMBLYREFPROCESSOR,
	MONO_TABLE_ASSEMBLYREFOS,
	MONO_TABLE_FILE,
	MONO_TABLE_EXPORTEDTYPE,
	MONO_TABLE_MANIFESTRESOURCE,
	MONO_TABLE_NESTEDCLASS,
	MONO_TABLE_GENERICPARAM, /* 0x2a */
	MONO_TABLE_METHODSPEC,
	MONO_TABLE_GENERICPARAMCONSTRAINT
} MonoMetaTableEnum;


enum {
	MONO_TYPEDEF_FLAGS,
	MONO_TYPEDEF_NAME,
	MONO_TYPEDEF_NAMESPACE,
	MONO_TYPEDEF_EXTENDS,
	MONO_TYPEDEF_FIELD_LIST,
	MONO_TYPEDEF_METHOD_LIST,
	MONO_TYPEDEF_SIZE
};

enum {
	MONO_METHOD_RVA,
	MONO_METHOD_IMPLFLAGS,
	MONO_METHOD_FLAGS,
	MONO_METHOD_NAME,
	MONO_METHOD_SIGNATURE,
	MONO_METHOD_PARAMLIST,
	MONO_METHOD_SIZE
};


typedef enum {
	MONO_TOKEN_MODULE = 0x00000000,
	MONO_TOKEN_TYPE_REF = 0x01000000,
	MONO_TOKEN_TYPE_DEF = 0x02000000,
	MONO_TOKEN_FIELD_DEF = 0x04000000,
	MONO_TOKEN_METHOD_DEF = 0x06000000,
	MONO_TOKEN_PARAM_DEF = 0x08000000,
	MONO_TOKEN_INTERFACE_IMPL = 0x09000000,
	MONO_TOKEN_MEMBER_REF = 0x0a000000,
	MONO_TOKEN_CUSTOM_ATTRIBUTE = 0x0c000000,
	MONO_TOKEN_PERMISSION = 0x0e000000,
	MONO_TOKEN_SIGNATURE = 0x11000000,
	MONO_TOKEN_EVENT = 0x14000000,
	MONO_TOKEN_PROPERTY = 0x17000000,
	MONO_TOKEN_MODULE_REF = 0x1a000000,
	MONO_TOKEN_TYPE_SPEC = 0x1b000000,
	MONO_TOKEN_ASSEMBLY = 0x20000000,
	MONO_TOKEN_ASSEMBLY_REF = 0x23000000,
	MONO_TOKEN_FILE = 0x26000000,
	MONO_TOKEN_EXPORTED_TYPE = 0x27000000,
	MONO_TOKEN_MANIFEST_RESOURCE = 0x28000000,
	MONO_TOKEN_GENERIC_PARAM = 0x2a000000,
	MONO_TOKEN_METHOD_SPEC = 0x2b000000,

	/*
	 * These do not match metadata tables directly
	 */
	 MONO_TOKEN_STRING = 0x70000000,
	 MONO_TOKEN_NAME = 0x71000000,
	 MONO_TOKEN_BASE_TYPE = 0x72000000
} MonoTokenType;