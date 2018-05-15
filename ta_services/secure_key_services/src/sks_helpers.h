/*
 * Copyright (c) 2017-2018, Linaro Limited
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef __SKS_HELPERS_H
#define __SKS_HELPERS_H

#include <sks_ta.h>
#include <stdint.h>
#include <stddef.h>
#include <tee_internal_api.h>

/*
 * Helper functions to analyse CK fields
 */
bool valid_sks_attribute_id(uint32_t id, uint32_t size);

size_t sks_attr_is_class(uint32_t attribute_id);
size_t sks_attr_is_type(uint32_t attribute_id);
bool sks_class_has_boolprop(uint32_t class);
bool sks_class_has_type(uint32_t class);
bool sks_attr_class_is_key(uint32_t class);
int sks_attr2boolprop_shift(uint32_t attr);

#define SKS_COMMAND_IDS \
	SKS_ID(SKS_CMD_PING) \
	SKS_ID(SKS_CMD_CK_SLOT_LIST) \
	SKS_ID(SKS_CMD_CK_SLOT_INFO) \
	SKS_ID(SKS_CMD_CK_TOKEN_INFO) \
	SKS_ID(SKS_CMD_CK_MECHANISM_IDS) \
	SKS_ID(SKS_CMD_CK_MECHANISM_INFO) \
	SKS_ID(SKS_CMD_CK_INIT_TOKEN) \
	SKS_ID(SKS_CMD_CK_INIT_PIN) \
	SKS_ID(SKS_CMD_CK_SET_PIN) \
	SKS_ID(SKS_CMD_CK_OPEN_RO_SESSION) \
	SKS_ID(SKS_CMD_CK_OPEN_RW_SESSION) \
	SKS_ID(SKS_CMD_CK_CLOSE_SESSION) \
	SKS_ID(SKS_CMD_CK_SESSION_INFO) \
	SKS_ID(SKS_CMD_CK_CLOSE_ALL_SESSIONS) \
	SKS_ID(SKS_CMD_IMPORT_OBJECT) \
	SKS_ID(SKS_CMD_DESTROY_OBJECT) \
	SKS_ID(SKS_CMD_ENCRYPT_INIT) \
	SKS_ID(SKS_CMD_DECRYPT_INIT) \
	SKS_ID(SKS_CMD_ENCRYPT_UPDATE) \
	SKS_ID(SKS_CMD_DECRYPT_UPDATE) \
	SKS_ID(SKS_CMD_ENCRYPT_FINAL) \
	SKS_ID(SKS_CMD_DECRYPT_FINAL) \
	SKS_ID(SKS_CMD_GENERATE_SYMM_KEY) \
	SKS_ID(SKS_CMD_SIGN_INIT) \
	SKS_ID(SKS_CMD_VERIFY_INIT) \
	SKS_ID(SKS_CMD_SIGN_UPDATE) \
	SKS_ID(SKS_CMD_VERIFY_UPDATE) \
	SKS_ID(SKS_CMD_SIGN_FINAL) \
	SKS_ID(SKS_CMD_VERIFY_FINAL) \
	SKS_ID(SKS_CMD_FIND_OBJECTS_INIT) \
	SKS_ID(SKS_CMD_FIND_OBJECTS) \
	SKS_ID(SKS_CMD_FIND_OBJECTS_FINAL) \
	/* the end */

#define SKS_ERROR_CODES \
	SKS_ID(SKS_OK) \
	SKS_ID(SKS_ERROR) \
	SKS_ID(SKS_MEMORY) \
	SKS_ID(SKS_BAD_PARAM) \
	SKS_ID(SKS_SHORT_BUFFER) \
	SKS_ID(SKS_FAILED) \
	SKS_ID(SKS_NOT_FOUND) \
	SKS_ID(SKS_VERIFY_FAILED) \
	SKS_ID(SKS_INVALID_ATTRIBUTES) \
	SKS_ID(SKS_INVALID_TYPE) \
	SKS_ID(SKS_INVALID_VALUE) \
	SKS_ID(SKS_INVALID_OBJECT) \
	SKS_ID(SKS_INVALID_KEY) \
	SKS_ID(SKS_INVALID_PROC) \
	SKS_ID(SKS_INVALID_SESSION) \
	SKS_ID(SKS_INVALID_SLOT) \
	SKS_ID(SKS_INVALID_PROC_PARAM) \
	SKS_ID(SKS_PIN_INCORRECT) \
	SKS_ID(SKS_PIN_LOCKED) \
	SKS_ID(SKS_PIN_EXPIRED) \
	SKS_ID(SKS_PIN_INVALID) \
	SKS_ID(SKS_CK_SESSION_PENDING) \
	SKS_ID(SKS_CK_SESSION_IS_READ_ONLY) \
	SKS_ID(SKS_CK_SO_IS_LOGGED_READ_WRITE) \
	SKS_ID(SKS_PROCESSING_ACTIVE) \
	SKS_ID(SKS_CK_NOT_PERMITTED) \
	SKS_ID(SKS_PROCESSING_INACTIVE) \
	SKS_ID(SKS_UNDEFINED_ID)
	/* the end */

#define SKS_SLOT_FLAG_MASKS \
	SKS_ID(SKS_TOKEN_PRESENT) \
	SKS_ID(SKS_TOKEN_REMOVABLE) \
	SKS_ID(SKS_TOKEN_HW) \
	/* the end */

#define SKS_TOKEN_FLAG_MASKS \
	SKS_ID(SKS_TOKEN_HAS_RNG) \
	SKS_ID(SKS_TOKEN_IS_READ_ONLY) \
	SKS_ID(SKS_TOKEN_REQUIRE_LOGIN) \
	SKS_ID(SKS_TOKEN_HAS_USER_PIN) \
	SKS_ID(SKS_TOKEN_FULLY_RESTORABLE) \
	SKS_ID(SKS_TOKEN_HAS_CLOCK) \
	SKS_ID(SKS_TOKEN_ALT_AUTHENT) \
	SKS_ID(SKS_TOKEN_CAN_DUAL_PROC) \
	SKS_ID(SKS_TOKEN_INITED) \
	SKS_ID(SKS_TOKEN_USR_PIN_FAILURE) \
	SKS_ID(SKS_TOKEN_USR_PIN_LAST) \
	SKS_ID(SKS_TOKEN_USR_PIN_LOCKED) \
	SKS_ID(SKS_TOKEN_USR_PIN_TO_CHANGE) \
	SKS_ID(SKS_TOKEN_SO_PIN_FAILURE) \
	SKS_ID(SKS_TOKEN_SO_PIN_LAST) \
	SKS_ID(SKS_TOKEN_SO_PIN_LOCKED) \
	SKS_ID(SKS_TOKEN_SO_PIN_TO_CHANGE) \
	SKS_ID(SKS_TOKEN_BAD_STATE) \
	/* the end */

#define SKS_MECHANISM_FLAG_IDS \
	SKS_ID(SKS_PROC_HW) \
	SKS_ID(SKS_PROC_ENCRYPT) \
	SKS_ID(SKS_PROC_DECRYPT) \
	SKS_ID(SKS_PROC_DIGEST) \
	SKS_ID(SKS_PROC_SIGN) \
	SKS_ID(SKS_PROC_SIGN_RECOVER) \
	SKS_ID(SKS_PROC_VERIFY) \
	SKS_ID(SKS_PROC_VERFIY_RECOVER) \
	SKS_ID(SKS_PROC_GENERATE) \
	SKS_ID(SKS_PROC_GENERATE_PAIR) \
	SKS_ID(SKS_PROC_WRAP) \
	SKS_ID(SKS_PROC_UNWRAP) \
	SKS_ID(SKS_PROC_DERIVE) \
	/* the end */

/*
 * 1st field: identification nummber for the attribute
 * 2nd field: expected byte size for the attribute or 0 if variable
 */
#define SKS_ATTRIBS_IDS \
	SKS_ID_SZ(SKS_CLASS,		4) \
	SKS_ID_SZ(SKS_TYPE,		4) \
	SKS_ID_SZ(SKS_VALUE,		0) \
	SKS_ID_SZ(SKS_VALUE_LEN,	4) \
	SKS_ID_SZ(SKS_WRAP_ATTRIBS,	0) \
	SKS_ID_SZ(SKS_UNWRAP_ATTRIBS,	0) \
	SKS_ID_SZ(SKS_DERIVE_ATTRIBS,	0) \
	SKS_ID_SZ(SKS_ACTIVATION_DATE,	4) \
	SKS_ID_SZ(SKS_REVOKATION_DATE,	4) \
	SKS_ID_SZ(SKS_OBJECT_ID,	0) \
	SKS_ID_SZ(SKS_APPLICATION_ID,	0) \
	SKS_ID_SZ(SKS_PROCESSING_ID,	4) \
	SKS_ID_SZ(SKS_KEY_ID,		0) \
	SKS_ID_SZ(SKS_ALLOWED_PROCESSINGS, 0) \
	/* Below are boolean attribs related to crypotoki boolean attribs */ \
	SKS_ID_SZ(SKS_PERSISTENT,	1) \
	SKS_ID_SZ(SKS_NEED_AUTHEN,	1) \
	SKS_ID_SZ(SKS_TRUSTED,		1) \
	SKS_ID_SZ(SKS_SENSITIVE,	1) \
	SKS_ID_SZ(SKS_ENCRYPT,		1) \
	SKS_ID_SZ(SKS_DECRYPT,		1) \
	SKS_ID_SZ(SKS_WRAP,		1) \
	SKS_ID_SZ(SKS_UNWRAP,		1) \
	SKS_ID_SZ(SKS_SIGN,		1) \
	SKS_ID_SZ(SKS_SIGN_RECOVER,	1) \
	SKS_ID_SZ(SKS_VERIFY,		1) \
	SKS_ID_SZ(SKS_VERIFY_RECOVER,	1) \
	SKS_ID_SZ(SKS_DERIVE,		1) \
	SKS_ID_SZ(SKS_EXTRACTABLE,	1) \
	SKS_ID_SZ(SKS_LOCALLY_GENERATED, 1) \
	SKS_ID_SZ(SKS_NEVER_EXTRACTABLE, 1) \
	SKS_ID_SZ(SKS_ALWAYS_SENSITIVE, 1) \
	SKS_ID_SZ(SKS_MODIFIABLE,	1) \
	SKS_ID_SZ(SKS_COPYABLE,		1) \
	SKS_ID_SZ(SKS_DESTROYABLE,	1) \
	SKS_ID_SZ(SKS_ALWAYS_AUTHEN,	1) \
	SKS_ID_SZ(SKS_WRAP_FROM_TRUSTED, 1) \
	/* Specifc SKS attribute IDs */ \
	SKS_ID_SZ(SKS_UNDEFINED_ID,	0)
	/* the end */

#define SKS_BOOLPROP_ATTRIBS_IDS \
	SKS_ID(SKS_BP_PERSISTENT) \
	SKS_ID(SKS_BP_NEED_AUTHEN) \
	SKS_ID(SKS_BP_TRUSTED) \
	SKS_ID(SKS_BP_SENSITIVE) \
	SKS_ID(SKS_BP_ENCRYPT) \
	SKS_ID(SKS_BP_DECRYPT) \
	SKS_ID(SKS_BP_WRAP) \
	SKS_ID(SKS_BP_UNWRAP) \
	SKS_ID(SKS_BP_SIGN) \
	SKS_ID(SKS_BP_SIGN_RECOVER) \
	SKS_ID(SKS_BP_VERIFY) \
	SKS_ID(SKS_BP_VERIFY_RECOVER) \
	SKS_ID(SKS_BP_DERIVE) \
	SKS_ID(SKS_BP_EXTRACTABLE) \
	SKS_ID(SKS_BP_LOCALLY_GENERATED) \
	SKS_ID(SKS_BP_NEVER_EXTRACTABLE) \
	SKS_ID(SKS_BP_ALWAYS_SENSITIVE) \
	SKS_ID(SKS_BP_MODIFIABLE) \
	SKS_ID(SKS_BP_COPYABLE) \
	SKS_ID(SKS_BP_DESTROYABLE) \
	SKS_ID(SKS_BP_ALWAYS_AUTHEN) \
	SKS_ID(SKS_BP_WRAP_FROM_TRUSTED)
	/* the end */

#define SKS_OBJECT_CLASS_IDS \
	SKS_ID(SKS_OBJ_SYM_KEY) \
	SKS_ID(SKS_OBJ_PUB_KEY) \
	SKS_ID(SKS_OBJ_PRIV_KEY) \
	SKS_ID(SKS_OBJ_OTP_KEY) \
	SKS_ID(SKS_OBJ_CERTIFICATE) \
	SKS_ID(SKS_OBJ_RAW_DATA) \
	SKS_ID(SKS_OBJ_CK_DOMAIN_PARAMS) \
	SKS_ID(SKS_OBJ_CK_HW_FEATURES) \
	SKS_ID(SKS_OBJ_CK_MECHANISM) \
	SKS_ID(SKS_UNDEFINED_ID)
	/* the end */

#define SKS_KEY_TYPE_IDS \
	SKS_ID(SKS_KEY_AES) \
	SKS_ID(SKS_GENERIC_SECRET) \
	SKS_ID(SKS_KEY_HMAC_MD5) \
	SKS_ID(SKS_KEY_HMAC_SHA1) \
	SKS_ID(SKS_KEY_HMAC_SHA224) \
	SKS_ID(SKS_KEY_HMAC_SHA256) \
	SKS_ID(SKS_KEY_HMAC_SHA384) \
	SKS_ID(SKS_KEY_HMAC_SHA512) \
	SKS_ID(SKS_UNDEFINED_ID)
	/* the end */

#define SKS_PROCESSING_IDS \
	SKS_ID(SKS_PROC_AES_ECB_NOPAD) \
	SKS_ID(SKS_PROC_AES_CBC_NOPAD) \
	SKS_ID(SKS_PROC_AES_CBC_PAD) \
	SKS_ID(SKS_PROC_AES_CTR) \
	SKS_ID(SKS_PROC_AES_GCM) \
	SKS_ID(SKS_PROC_AES_CCM) \
	SKS_ID(SKS_PROC_AES_CTS) \
	SKS_ID(SKS_PROC_AES_GMAC) \
	SKS_ID(SKS_PROC_AES_CMAC) \
	SKS_ID(SKS_PROC_AES_CMAC_GENERAL) \
	SKS_ID(SKS_PROC_AES_DERIVE_BY_ECB) \
	SKS_ID(SKS_PROC_AES_DERIVE_BY_CBC) \
	SKS_ID(SKS_PROC_AES_GENERATE) \
	SKS_ID(SKS_PROC_GENERIC_GENERATE) \
	SKS_ID(SKS_PROC_HMAC_MD5) \
	SKS_ID(SKS_PROC_HMAC_SHA1) \
	SKS_ID(SKS_PROC_HMAC_SHA224) \
	SKS_ID(SKS_PROC_HMAC_SHA256) \
	SKS_ID(SKS_PROC_HMAC_SHA384) \
	SKS_ID(SKS_PROC_HMAC_SHA512) \
	SKS_ID(SKS_PROC_AES_CBC_MAC) \
	SKS_ID(SKS_UNDEFINED_ID)
	/* the end */

/*
 * Convert SKS retrun code into a GPD TEE result ID when matching.
 * If not, return a TEE success (_noerr) or generic error (_error).
 */
TEE_Result sks2tee_noerr(uint32_t rv);
TEE_Result sks2tee_error(uint32_t rv);
uint32_t tee2sks_error(TEE_Result res);

#if CFG_TEE_TA_LOG_LEVEL > 0
const char *sks2str_attr(uint32_t id);
const char *sks2str_class(uint32_t id);
const char *sks2str_type(uint32_t id, uint32_t class);
const char *sks2str_key_type(uint32_t id);
const char *sks2str_boolprop(uint32_t id);
const char *sks2str_proc(uint32_t id);
const char *sks2str_proc_flag(uint32_t id);
const char *sks2str_slot_flag(uint32_t id);
const char *sks2str_token_flag(uint32_t id);
const char *sks2str_rc(uint32_t id);
const char *sks2str_skscmd(uint32_t id);
#endif

#endif /*__CK_HELPERS_H*/
