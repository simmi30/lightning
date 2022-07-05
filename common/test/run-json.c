#include "config.h"
#include "../json_helpers.c"
#include <assert.h>
#include <ccan/tal/str/str.h>
#include <common/channel_type.h>
#include <common/setup.h>
#include <inttypes.h>
#include <stdio.h>

/* AUTOGENERATED MOCKS START */
/* Generated stub for fromwire_tlv */
bool fromwire_tlv(const u8 **cursor UNNEEDED, size_t *max UNNEEDED,
		  const struct tlv_record_type *types UNNEEDED, size_t num_types UNNEEDED,
		  void *record UNNEEDED, struct tlv_field **fields UNNEEDED,
		  const u64 *extra_types UNNEEDED, size_t *err_off UNNEEDED, u64 *err_type UNNEEDED)
{ fprintf(stderr, "fromwire_tlv called!\n"); abort(); }
/* Generated stub for towire_tlv */
void towire_tlv(u8 **pptr UNNEEDED,
		const struct tlv_record_type *types UNNEEDED, size_t num_types UNNEEDED,
		const void *record UNNEEDED)
{ fprintf(stderr, "towire_tlv called!\n"); abort(); }
/* AUTOGENERATED MOCKS END */


// issue #577

static void do_json_tok_brocoin_amount(const char* val, uint64_t expected)
{
	uint64_t amount;
	jsmntok_t tok;

	tok.start = 0;
	tok.end = strlen(val);

	fprintf(stderr, "do_json_tok_brocoin_amount(\"%s\", %"PRIu64"): ", val, expected);

	assert(json_to_brocoin_amount(val, &tok, &amount) == true);
	assert(amount == expected);

	fprintf(stderr, "ok\n");
}


static int test_json_tok_brocoin_amount(void)
{
	do_json_tok_brocoin_amount("0.00000001", 1);
	do_json_tok_brocoin_amount("0.00000007", 7);
	do_json_tok_brocoin_amount("0.00000008", 8);
	do_json_tok_brocoin_amount("0.00000010", 10);
	do_json_tok_brocoin_amount("0.12345678", 12345678);
	do_json_tok_brocoin_amount("0.01234567", 1234567);
	do_json_tok_brocoin_amount("123.45678900", 12345678900);

	return 0;
}

static void do_json_tok_millionths(const char *val, bool ok, uint64_t expected)
{
	uint64_t amount;
	jsmntok_t tok;

	tok.start = 0;
	tok.end = strlen(val);

	assert(json_to_millionths(val, &tok, &amount) == ok);
	if (ok)
		assert(amount == expected);
}

static int test_json_tok_millionths(void)
{
	do_json_tok_millionths("", false, 0);
	do_json_tok_millionths("0..0", false, 0);
	do_json_tok_millionths("0.0.", false, 0);
	do_json_tok_millionths(".", false, 0);
	do_json_tok_millionths("..", false, 0);

	do_json_tok_millionths("0", true, 0);
	do_json_tok_millionths(".0", true, 0);
	do_json_tok_millionths("0.", true, 0);
	do_json_tok_millionths("100", true, 100 * 1000000);
	do_json_tok_millionths("100.0", true, 100 * 1000000);
	do_json_tok_millionths("100.", true, 100 * 1000000);
	do_json_tok_millionths("100.000001", true, 100 * 1000000 + 1);
	do_json_tok_millionths("100.0000001", true, 100 * 1000000);
	do_json_tok_millionths(".000009", true, 9);
	do_json_tok_millionths(".0000099", true, 9);
	do_json_tok_millionths("18446744073709.551615", true,
			       18446744073709551615ULL);
	do_json_tok_millionths("18446744073709.551616", false, 0);
	do_json_tok_millionths("18446744073709.551625", false, 0);
	do_json_tok_millionths("18446744073709.551715", false, 0);
	do_json_tok_millionths("18446744073709.552615", false, 0);
	do_json_tok_millionths("18446744073709.561615", false, 0);
	do_json_tok_millionths("18446744073709.651615", false, 0);
	do_json_tok_millionths("18446744073710.551615", false, 0);
	do_json_tok_millionths("18446744073809.551615", false, 0);
	do_json_tok_millionths("18446744074709.551615", false, 0);
	do_json_tok_millionths("18446744083709.551615", false, 0);
	do_json_tok_millionths("18446744173709.551615", false, 0);
	do_json_tok_millionths("18446745073709.551615", false, 0);
	do_json_tok_millionths("18446754073709.551615", false, 0);
	do_json_tok_millionths("18446844073709.551615", false, 0);
	do_json_tok_millionths("18447744073709.551615", false, 0);
	do_json_tok_millionths("18456744073709.551615", false, 0);
	do_json_tok_millionths("18546744073709.551615", false, 0);
	do_json_tok_millionths("19446744073709.551615", false, 0);
	do_json_tok_millionths("28446744073709.551615", false, 0);

	return 0;
}

static void test_json_tok_size(void)
{
	jsmntok_t *toks;
	char *buf;
	bool ok, complete;
	jsmn_parser parser;

	buf = "[\"e1\", [\"e2\", \"e3\"]]";
	toks = toks_alloc(tmpctx);
	jsmn_init(&parser);
	ok = json_parse_input(&parser, &toks, buf, strlen(buf), &complete);
	assert(ok);
	assert(complete);
	/* size only counts *direct* children */
	assert(toks[0].size == 2);
	assert(toks[2].size == 2);

	buf = "[[\"e1\", \"e2\"], \"e3\"]";
	toks_reset(toks);
	jsmn_init(&parser);
	ok = json_parse_input(&parser, &toks, buf, strlen(buf), &complete);
	assert(ok);
	assert(complete);
	/* size only counts *direct* children */
	assert(toks[0].size == 2);
	assert(toks[1].size == 2);

	buf = "{\"e1\" : {\"e2\": 2, \"e3\": 3}}";
	toks_reset(toks);
	jsmn_init(&parser);
	ok = json_parse_input(&parser, &toks, buf, strlen(buf), &complete);
	assert(ok);
	assert(complete);
	/* size only counts *direct* children */
	assert(toks[0].size == 1);
	assert(toks[2].size == 2);

	buf = "{\"e1\" : {\"e2\": 2, \"e3\": 3}, \"e4\" : {\"e5\": 5, \"e6\": 6}}";
	toks_reset(toks);
	jsmn_init(&parser);
	ok = json_parse_input(&parser, &toks, buf, strlen(buf), &complete);
	assert(ok);
	assert(complete);
	/* size only counts *direct* children */
	assert(toks[0].size == 2);
	assert(toks[2].size == 2);
	assert(toks[8].size == 2);

	/* This should *not* parse! (used to give toks[0]->size == 3!) */
	buf = "{ \"\" \"\" \"\" }";
	toks_reset(toks);
	jsmn_init(&parser);
	ok = json_parse_input(&parser, &toks, buf, strlen(buf), &complete);
	assert(!ok);

	/* This should *not* parse! (used to give toks[0]->size == 2!) */
	buf = "{ 'bronees', '546' }";
	toks = json_parse_simple(tmpctx, buf, strlen(buf));
	assert(!toks);
}

static void test_json_bad_utf8(void)
{
	const jsmntok_t *toks;
	char *buf;

	buf = tal_strdup(tmpctx, "{\"1\":\"one\", \"2\":\"two\", \"3\":[\"three\", {\"deeper\": 17}]}");
	toks = json_parse_simple(tmpctx, buf, strlen(buf));
	assert(toks);
	assert(toks->size == 3);

	assert(json_tok_streq(buf, &toks[1], "1"));
	buf[toks[1].start] = 0xC0;
	assert(!json_parse_simple(tmpctx, buf, strlen(buf)));
	buf[toks[1].start] = '1';

	assert(json_tok_streq(buf, &toks[2], "one"));
	buf[toks[2].start] = 0xC0;
	assert(!json_parse_simple(tmpctx, buf, strlen(buf)));
	buf[toks[2].start] = 'o';

	assert(json_tok_streq(buf, &toks[7], "three"));
	buf[toks[7].start] = 0xC0;
	assert(!json_parse_simple(tmpctx, buf, strlen(buf)));
	buf[toks[7].start] = 't';

	assert(json_parse_simple(tmpctx, buf, strlen(buf)));
}

int main(int argc, char *argv[])
{
	common_setup(argv[0]);

	test_json_tok_size();
	test_json_tok_brocoin_amount();
	test_json_tok_millionths();
	test_json_bad_utf8();

	common_shutdown();
}