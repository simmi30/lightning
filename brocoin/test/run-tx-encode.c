#include "config.h"
#include <assert.h>
#include <brocoin/psbt.c>
#include <brocoin/shadouble.c>
#include <brocoin/tx.c>
#include <brocoin/varint.c>
#include <ccan/str/hex/hex.h>
#include <common/setup.h>
#include <common/utils.h>
#include <stdio.h>

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
/* Generated stub for fromwire_fail */
void *fromwire_fail(const u8 **cursor UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_fail called!\n"); abort(); }
/* Generated stub for fromwire_sha256 */
void fromwire_sha256(const u8 **cursor UNNEEDED, size_t *max UNNEEDED, struct sha256 *sha256 UNNEEDED)
{ fprintf(stderr, "fromwire_sha256 called!\n"); abort(); }
/* Generated stub for fromwire_u32 */
u32 fromwire_u32(const u8 **cursor UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_u32 called!\n"); abort(); }
/* Generated stub for is_anchor_witness_script */
bool is_anchor_witness_script(const u8 *script UNNEEDED, size_t script_len UNNEEDED)
{ fprintf(stderr, "is_anchor_witness_script called!\n"); abort(); }
/* Generated stub for pubkey_to_der */
void pubkey_to_der(u8 der[PUBKEY_CMPR_LEN] UNNEEDED, const struct pubkey *key UNNEEDED)
{ fprintf(stderr, "pubkey_to_der called!\n"); abort(); }
/* Generated stub for pubkey_to_hash160 */
void pubkey_to_hash160(const struct pubkey *pk UNNEEDED, struct ripemd160 *hash UNNEEDED)
{ fprintf(stderr, "pubkey_to_hash160 called!\n"); abort(); }
/* Generated stub for script_push_bytes */
void script_push_bytes(u8 **scriptp UNNEEDED, const void *mem UNNEEDED, size_t len UNNEEDED)
{ fprintf(stderr, "script_push_bytes called!\n"); abort(); }
/* Generated stub for scriptpubkey_p2wsh */
u8 *scriptpubkey_p2wsh(const tal_t *ctx UNNEEDED, const u8 *witnessscript UNNEEDED)
{ fprintf(stderr, "scriptpubkey_p2wsh called!\n"); abort(); }
/* Generated stub for towire_sha256 */
void towire_sha256(u8 **pptr UNNEEDED, const struct sha256 *sha256 UNNEEDED)
{ fprintf(stderr, "towire_sha256 called!\n"); abort(); }
/* Generated stub for towire_u32 */
void towire_u32(u8 **pptr UNNEEDED, u32 v UNNEEDED)
{ fprintf(stderr, "towire_u32 called!\n"); abort(); }
/* Generated stub for towire_u8_array */
void towire_u8_array(u8 **pptr UNNEEDED, const u8 *arr UNNEEDED, size_t num UNNEEDED)
{ fprintf(stderr, "towire_u8_array called!\n"); abort(); }
/* AUTOGENERATED MOCKS END */

const char extended_tx[] =
    "02000000000101b5bef485c41d0d1f58d1e8a561924ece5c476d86cff063ea10c8df06136e"
    "b31d00000000171600144aa38e396e1394fb45cbf83f48d1464fbc9f498fffffffff014033"
    "0f000000000017a9140580ba016669d3efaf09a0b2ec3954469ea2bf038702483045022100"
    "f2abf9e9cf238c66533af93f23937eae8ac01fb6f105a00ab71dbefb9637dc9502205c1ac7"
    "45829b3f6889607961f5d817dfa0c8f52bdda12e837c4f7b162f6db8a701210204096eb817"
    "f7efb414ef4d3d8be39dd04374256d3b054a322d4a6ee22736d03b00000000";

static void hexeq(const void *p, size_t len, const char *hex)
{
	char *tmphex = tal_hexstr(NULL, p, len);

	if (!streq(hex, tmphex)) {
		fprintf(stderr, "Expected '%s' got '%s'", hex, tmphex);
		abort();
	}
	tal_free(tmphex);
}

int main(int argc, const char *argv[])
{
	common_setup(argv[0]);
	chainparams = chainparams_for_network("brocoin");

	struct brocoin_tx *tx;

	tx = brocoin_tx_from_hex(NULL, extended_tx, strlen(extended_tx));
	assert(tx);

	/* Canonical results from Nichola Dorier's
	 *	   http://n.brocoin.ninja/checktx
	 * With much thanks!
	 */
	assert(tx->wtx->num_inputs == 1);
	assert(tx->wtx->num_outputs == 1);

	reverse_bytes(tx->wtx->inputs[0].txhash,
		      sizeof(tx->wtx->inputs[0].txhash));
	hexeq(tx->wtx->inputs[0].txhash, sizeof(tx->wtx->inputs[0].txhash),
	      "1db36e1306dfc810ea63f0cf866d475cce4e9261a5e8d1581f0d1dc485f4beb5");
	assert(tx->wtx->inputs[0].index == 0);

	/* This is a p2sh-p2wpkh: */
	/* ScriptSig is push of "version 0 + hash of pubkey" */
	hexeq(tx->wtx->inputs[0].script, tx->wtx->inputs[0].script_len,
	      "16" "00" "144aa38e396e1394fb45cbf83f48d1464fbc9f498f");

	/* Witness with 2 items */
	assert(tx->wtx->inputs[0].witness);
	assert(tx->wtx->inputs[0].witness->num_items == 2);

	hexeq(tx->wtx->inputs[0].witness->items[0].witness,
	      tx->wtx->inputs[0].witness->items[0].witness_len,
	      "3045022100f2abf9e9cf238c66533af93f23937eae8ac01fb6f105a00ab71dbe"
	      "fb9637dc9502205c1ac745829b3f6889607961f5d817dfa0c8f52bdda12e837c"
	      "4f7b162f6db8a701");
	hexeq(tx->wtx->inputs[0].witness->items[1].witness,
	      tx->wtx->inputs[0].witness->items[1].witness_len,
	      "0204096eb817f7efb414ef4d3d8be39dd04374256d3b054a322d4a6ee22736d0"
	      "3b");

	tal_free(tx);
	common_shutdown();
	return 0;
}
