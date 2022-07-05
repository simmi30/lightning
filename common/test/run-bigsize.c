#include "config.h"
#include <ccan/array_size/array_size.h>
#include <ccan/tal/grab_file/grab_file.h>
#include <common/amount.h>
#include <common/json.c>
#include <common/setup.h>

static const char *reason;
#define SUPERVERBOSE(r) do { if (!reason) reason = (r); } while(0)

#include <common/bigsize.c>

/* AUTOGENERATED MOCKS START */
/* Generated stub for amount_asset_is_main */
bool amount_asset_is_main(struct amount_asset *asset UNNEEDED)
{ fprintf(stderr, "amount_asset_is_main called!\n"); abort(); }
/* Generated stub for amount_asset_to_bro */
struct amount_bro amount_asset_to_bro(struct amount_asset *asset UNNEEDED)
{ fprintf(stderr, "amount_asset_to_bro called!\n"); abort(); }
/* Generated stub for amount_bro */
struct amount_bro amount_bro(u64 broneess UNNEEDED)
{ fprintf(stderr, "amount_bro called!\n"); abort(); }
/* Generated stub for amount_bro_add */
 bool amount_bro_add(struct amount_bro *val UNNEEDED,
				       struct amount_bro a UNNEEDED,
				       struct amount_bro b UNNEEDED)
{ fprintf(stderr, "amount_bro_add called!\n"); abort(); }
/* Generated stub for amount_bro_eq */
bool amount_bro_eq(struct amount_bro a UNNEEDED, struct amount_bro b UNNEEDED)
{ fprintf(stderr, "amount_bro_eq called!\n"); abort(); }
/* Generated stub for amount_bro_greater_eq */
bool amount_bro_greater_eq(struct amount_bro a UNNEEDED, struct amount_bro b UNNEEDED)
{ fprintf(stderr, "amount_bro_greater_eq called!\n"); abort(); }
/* Generated stub for amount_bro_sub */
 bool amount_bro_sub(struct amount_bro *val UNNEEDED,
				       struct amount_bro a UNNEEDED,
				       struct amount_bro b UNNEEDED)
{ fprintf(stderr, "amount_bro_sub called!\n"); abort(); }
/* Generated stub for amount_bro_to_asset */
struct amount_asset amount_bro_to_asset(struct amount_bro *bro UNNEEDED, const u8 *asset UNNEEDED)
{ fprintf(stderr, "amount_bro_to_asset called!\n"); abort(); }
/* Generated stub for amount_tx_fee */
struct amount_bro amount_tx_fee(u32 fee_per_kw UNNEEDED, size_t weight UNNEEDED)
{ fprintf(stderr, "amount_tx_fee called!\n"); abort(); }
/* Generated stub for fromwire */
const u8 *fromwire(const u8 **cursor UNNEEDED, size_t *max UNNEEDED, void *copy UNNEEDED, size_t n UNNEEDED)
{ fprintf(stderr, "fromwire called!\n"); abort(); }
/* Generated stub for fromwire_bool */
bool fromwire_bool(const u8 **cursor UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_bool called!\n"); abort(); }
/* Generated stub for fromwire_fail */
void *fromwire_fail(const u8 **cursor UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_fail called!\n"); abort(); }
/* Generated stub for fromwire_secp256k1_ecdsa_signature */
void fromwire_secp256k1_ecdsa_signature(const u8 **cursor UNNEEDED, size_t *max UNNEEDED,
					secp256k1_ecdsa_signature *signature UNNEEDED)
{ fprintf(stderr, "fromwire_secp256k1_ecdsa_signature called!\n"); abort(); }
/* Generated stub for fromwire_sha256 */
void fromwire_sha256(const u8 **cursor UNNEEDED, size_t *max UNNEEDED, struct sha256 *sha256 UNNEEDED)
{ fprintf(stderr, "fromwire_sha256 called!\n"); abort(); }
/* Generated stub for fromwire_tal_arrn */
u8 *fromwire_tal_arrn(const tal_t *ctx UNNEEDED,
		       const u8 **cursor UNNEEDED, size_t *max UNNEEDED, size_t num UNNEEDED)
{ fprintf(stderr, "fromwire_tal_arrn called!\n"); abort(); }
/* Generated stub for fromwire_u32 */
u32 fromwire_u32(const u8 **cursor UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_u32 called!\n"); abort(); }
/* Generated stub for fromwire_u64 */
u64 fromwire_u64(const u8 **cursor UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_u64 called!\n"); abort(); }
/* Generated stub for fromwire_u8 */
u8 fromwire_u8(const u8 **cursor UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_u8 called!\n"); abort(); }
/* Generated stub for fromwire_u8_array */
void fromwire_u8_array(const u8 **cursor UNNEEDED, size_t *max UNNEEDED, u8 *arr UNNEEDED, size_t num UNNEEDED)
{ fprintf(stderr, "fromwire_u8_array called!\n"); abort(); }
/* Generated stub for json_add_member */
void json_add_member(struct json_stream *js UNNEEDED,
		     const char *fieldname UNNEEDED,
		     bool quote UNNEEDED,
		     const char *fmt UNNEEDED, ...)
{ fprintf(stderr, "json_add_member called!\n"); abort(); }
/* Generated stub for json_member_direct */
char *json_member_direct(struct json_stream *js UNNEEDED,
			 const char *fieldname UNNEEDED, size_t extra UNNEEDED)
{ fprintf(stderr, "json_member_direct called!\n"); abort(); }
/* Generated stub for towire */
void towire(u8 **pptr UNNEEDED, const void *data UNNEEDED, size_t len UNNEEDED)
{ fprintf(stderr, "towire called!\n"); abort(); }
/* Generated stub for towire_bool */
void towire_bool(u8 **pptr UNNEEDED, bool v UNNEEDED)
{ fprintf(stderr, "towire_bool called!\n"); abort(); }
/* Generated stub for towire_secp256k1_ecdsa_signature */
void towire_secp256k1_ecdsa_signature(u8 **pptr UNNEEDED,
			      const secp256k1_ecdsa_signature *signature UNNEEDED)
{ fprintf(stderr, "towire_secp256k1_ecdsa_signature called!\n"); abort(); }
/* Generated stub for towire_sha256 */
void towire_sha256(u8 **pptr UNNEEDED, const struct sha256 *sha256 UNNEEDED)
{ fprintf(stderr, "towire_sha256 called!\n"); abort(); }
/* Generated stub for towire_u32 */
void towire_u32(u8 **pptr UNNEEDED, u32 v UNNEEDED)
{ fprintf(stderr, "towire_u32 called!\n"); abort(); }
/* Generated stub for towire_u64 */
void towire_u64(u8 **pptr UNNEEDED, u64 v UNNEEDED)
{ fprintf(stderr, "towire_u64 called!\n"); abort(); }
/* Generated stub for towire_u8 */
void towire_u8(u8 **pptr UNNEEDED, u8 v UNNEEDED)
{ fprintf(stderr, "towire_u8 called!\n"); abort(); }
/* Generated stub for towire_u8_array */
void towire_u8_array(u8 **pptr UNNEEDED, const u8 *arr UNNEEDED, size_t num UNNEEDED)
{ fprintf(stderr, "towire_u8_array called!\n"); abort(); }
/* AUTOGENERATED MOCKS END */

/* BOLT #1:
 *
 * A correct implementation should pass against these test vectors:
 * ```json
 * [
 *     {
 *         "name": "zero",
 *         "value": 0,
 *         "bytes": "00"
 *     },
 *     {
 *         "name": "one byte high",
 *         "value": 252,
 *         "bytes": "fc"
 *     },
 *     {
 *         "name": "two byte low",
 *         "value": 253,
 *         "bytes": "fd00fd"
 *     },
 *     {
 *         "name": "two byte high",
 *         "value": 65535,
 *         "bytes": "fdffff"
 *     },
 *     {
 *         "name": "four byte low",
 *         "value": 65536,
 *         "bytes": "fe00010000"
 *     },
 *     {
 *         "name": "four byte high",
 *         "value": 4294967295,
 *         "bytes": "feffffffff"
 *     },
 *     {
 *         "name": "eight byte low",
 *         "value": 4294967296,
 *         "bytes": "ff0000000100000000"
 *     },
 *     {
 *         "name": "eight byte high",
 *         "value": 18446744073709551615,
 *         "bytes": "ffffffffffffffffff"
 *     },
 *     {
 *         "name": "two byte not canonical",
 *         "value": 0,
 *         "bytes": "fd00fc",
 *         "exp_error": "decoded bigsize is not canonical"
 *     },
 *     {
 *         "name": "four byte not canonical",
 *         "value": 0,
 *         "bytes": "fe0000ffff",
 *         "exp_error": "decoded bigsize is not canonical"
 *     },
 *     {
 *         "name": "eight byte not canonical",
 *         "value": 0,
 *         "bytes": "ff00000000ffffffff",
 *         "exp_error": "decoded bigsize is not canonical"
 *     },
 *     {
 *         "name": "two byte short read",
 *         "value": 0,
 *         "bytes": "fd00",
 *         "exp_error": "unexpected EOF"
 *     },
 *     {
 *         "name": "four byte short read",
 *         "value": 0,
 *         "bytes": "feffff",
 *         "exp_error": "unexpected EOF"
 *     },
 *     {
 *         "name": "eight byte short read",
 *         "value": 0,
 *         "bytes": "ffffffffff",
 *         "exp_error": "unexpected EOF"
 *     },
 *     {
 *         "name": "one byte no read",
 *         "value": 0,
 *         "bytes": "",
 *         "exp_error": "EOF"
 *     },
 *     {
 *         "name": "two byte no read",
 *         "value": 0,
 *         "bytes": "fd",
 *         "exp_error": "unexpected EOF"
 *     },
 *     {
 *         "name": "four byte no read",
 *         "value": 0,
 *         "bytes": "fe",
 *         "exp_error": "unexpected EOF"
 *     },
 *     {
 *         "name": "eight byte no read",
 *         "value": 0,
 *         "bytes": "ff",
 *         "exp_error": "unexpected EOF"
 *     }
 * ]
 * ```
 */
static void test_decode(const char *json, const jsmntok_t toks[])
{
	size_t i;
	const jsmntok_t *t;

	json_for_each_arr(i, t, toks) {
		const jsmntok_t *err = json_get_member(json, t, "exp_error");
		const jsmntok_t *bytes = json_get_member(json, t, "bytes");
		u64 num, expect;
		const u8 *b;
		size_t len;

		if (!json_to_u64(json, json_get_member(json, t, "value"),
				 &expect))
			abort();
		b = tal_hexdata(tmpctx, json + bytes->start,
				bytes->end - bytes->start);

		reason = NULL;
		len = bigsize_get(b, tal_bytelen(b), &num);
		if (err) {
			assert(len == 0);
			assert(json_tok_streq(json, err, reason));
		} else {
			assert(len == tal_bytelen(b));
			assert(num == expect);
		}
	}
}

/* BOLT #1:
 *
 * A correct implementation should pass against the following test vectors:
 * ```json
 * [
 *     {
 *         "name": "zero",
 *         "value": 0,
 *         "bytes": "00"
 *     },
 *     {
 *         "name": "one byte high",
 *         "value": 252,
 *         "bytes": "fc"
 *     },
 *     {
 *         "name": "two byte low",
 *         "value": 253,
 *         "bytes": "fd00fd"
 *     },
 *     {
 *         "name": "two byte high",
 *         "value": 65535,
 *         "bytes": "fdffff"
 *     },
 *     {
 *         "name": "four byte low",
 *         "value": 65536,
 *         "bytes": "fe00010000"
 *     },
 *     {
 *         "name": "four byte high",
 *         "value": 4294967295,
 *         "bytes": "feffffffff"
 *     },
 *     {
 *         "name": "eight byte low",
 *         "value": 4294967296,
 *         "bytes": "ff0000000100000000"
 *     },
 *     {
 *         "name": "eight byte high",
 *         "value": 18446744073709551615,
 *         "bytes": "ffffffffffffffffff"
 *     }
 * ]
 * ```
 */
static void test_encode(const char *json, const jsmntok_t toks[])
{
	size_t i;
	const jsmntok_t *t;
	u8 buf[BIGSIZE_MAX_LEN];

	json_for_each_arr(i, t, toks) {
		const jsmntok_t *bytes = json_get_member(json, t, "bytes");
		u64 num;
		const u8 *expect;
		size_t len;

		if (!json_to_u64(json, json_get_member(json, t, "value"),
				 &num))
			abort();
		expect = tal_hexdata(tmpctx, json + bytes->start,
				     bytes->end - bytes->start);

		len = bigsize_put(buf, num);
		assert(memeq(buf, len, expect, tal_bytelen(expect)));
	}
}

int main(int argc, char *argv[])
{
	char **lines, *json = NULL;
	int test_count = 0;

	common_setup(argv[0]);

	lines = tal_strsplit(tmpctx, grab_file(tmpctx, tal_fmt(tmpctx, "%s.c",
							       argv[0])),
			     "\n", STR_NO_EMPTY);

	for (size_t i = 0; lines[i]; i++) {
		const char *l = lines[i];
		if (!strstarts(l, " * "))
			continue;
		l += 3;
		if (streq(l, "```json"))
			json = tal_strdup(tmpctx, "");
		else if (streq(l, "```")) {
			jsmn_parser parser;
			jsmntok_t toks[500];

			jsmn_init(&parser);
			if (jsmn_parse(&parser, json, strlen(json),
				       toks, ARRAY_SIZE(toks)) < 0)
				abort();

			switch (test_count) {
			case 0:
				test_decode(json, toks);
				break;
			case 1:
				test_encode(json, toks);
				break;
			default:
				abort();
			}
			test_count++;
			json = NULL;
		} else if (json)
			tal_append_fmt(&json, "%s", l);
	}
	assert(test_count == 2);
	common_shutdown();
}