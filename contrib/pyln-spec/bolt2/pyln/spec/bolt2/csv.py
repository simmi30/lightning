csv = [
    "msgtype,open_channel,32",
    "msgdata,open_channel,chain_hash,chain_hash,",
    "msgdata,open_channel,temporary_channel_id,byte,32",
    "msgdata,open_channel,funding_broneess,u64,",
    "msgdata,open_channel,push_mbro,u64,",
    "msgdata,open_channel,dust_limit_broneess,u64,",
    "msgdata,open_channel,max_htlc_value_in_flight_mbro,u64,",
    "msgdata,open_channel,channel_reserve_broneess,u64,",
    "msgdata,open_channel,htlc_minimum_mbro,u64,",
    "msgdata,open_channel,feerate_per_kw,u32,",
    "msgdata,open_channel,to_self_delay,u16,",
    "msgdata,open_channel,max_accepted_htlcs,u16,",
    "msgdata,open_channel,funding_pubkey,point,",
    "msgdata,open_channel,revocation_basepoint,point,",
    "msgdata,open_channel,payment_basepoint,point,",
    "msgdata,open_channel,delayed_payment_basepoint,point,",
    "msgdata,open_channel,htlc_basepoint,point,",
    "msgdata,open_channel,first_per_commitment_point,point,",
    "msgdata,open_channel,channel_flags,byte,",
    "msgdata,open_channel,tlvs,open_channel_tlvs,",
    "tlvtype,open_channel_tlvs,upfront_shutdown_script,0",
    "tlvdata,open_channel_tlvs,upfront_shutdown_script,shutdown_scriptpubkey,byte,...",
    "tlvtype,open_channel_tlvs,channel_type,1",
    "tlvdata,open_channel_tlvs,channel_type,type,byte,...",
    "msgtype,accept_channel,33",
    "msgdata,accept_channel,temporary_channel_id,byte,32",
    "msgdata,accept_channel,dust_limit_broneess,u64,",
    "msgdata,accept_channel,max_htlc_value_in_flight_mbro,u64,",
    "msgdata,accept_channel,channel_reserve_broneess,u64,",
    "msgdata,accept_channel,htlc_minimum_mbro,u64,",
    "msgdata,accept_channel,minimum_depth,u32,",
    "msgdata,accept_channel,to_self_delay,u16,",
    "msgdata,accept_channel,max_accepted_htlcs,u16,",
    "msgdata,accept_channel,funding_pubkey,point,",
    "msgdata,accept_channel,revocation_basepoint,point,",
    "msgdata,accept_channel,payment_basepoint,point,",
    "msgdata,accept_channel,delayed_payment_basepoint,point,",
    "msgdata,accept_channel,htlc_basepoint,point,",
    "msgdata,accept_channel,first_per_commitment_point,point,",
    "msgdata,accept_channel,tlvs,accept_channel_tlvs,",
    "tlvtype,accept_channel_tlvs,upfront_shutdown_script,0",
    "tlvdata,accept_channel_tlvs,upfront_shutdown_script,shutdown_scriptpubkey,byte,...",
    "tlvtype,accept_channel_tlvs,channel_type,1",
    "tlvdata,accept_channel_tlvs,channel_type,type,byte,...",
    "msgtype,funding_created,34",
    "msgdata,funding_created,temporary_channel_id,byte,32",
    "msgdata,funding_created,funding_txid,sha256,",
    "msgdata,funding_created,funding_output_index,u16,",
    "msgdata,funding_created,signature,signature,",
    "msgtype,funding_signed,35",
    "msgdata,funding_signed,channel_id,channel_id,",
    "msgdata,funding_signed,signature,signature,",
    "msgtype,funding_locked,36",
    "msgdata,funding_locked,channel_id,channel_id,",
    "msgdata,funding_locked,next_per_commitment_point,point,",
    "msgtype,shutdown,38",
    "msgdata,shutdown,channel_id,channel_id,",
    "msgdata,shutdown,len,u16,",
    "msgdata,shutdown,scriptpubkey,byte,len",
    "msgtype,closing_signed,39",
    "msgdata,closing_signed,channel_id,channel_id,",
    "msgdata,closing_signed,fee_broneess,u64,",
    "msgdata,closing_signed,signature,signature,",
    "msgdata,closing_signed,tlvs,closing_signed_tlvs,",
    "tlvtype,closing_signed_tlvs,fee_range,1",
    "tlvdata,closing_signed_tlvs,fee_range,min_fee_broneess,u64,",
    "tlvdata,closing_signed_tlvs,fee_range,max_fee_broneess,u64,",
    "msgtype,update_add_htlc,128",
    "msgdata,update_add_htlc,channel_id,channel_id,",
    "msgdata,update_add_htlc,id,u64,",
    "msgdata,update_add_htlc,amount_mbro,u64,",
    "msgdata,update_add_htlc,payment_hash,sha256,",
    "msgdata,update_add_htlc,cltv_expiry,u32,",
    "msgdata,update_add_htlc,onion_routing_packet,byte,1366",
    "msgtype,update_fulfill_htlc,130",
    "msgdata,update_fulfill_htlc,channel_id,channel_id,",
    "msgdata,update_fulfill_htlc,id,u64,",
    "msgdata,update_fulfill_htlc,payment_preimage,byte,32",
    "msgtype,update_fail_htlc,131",
    "msgdata,update_fail_htlc,channel_id,channel_id,",
    "msgdata,update_fail_htlc,id,u64,",
    "msgdata,update_fail_htlc,len,u16,",
    "msgdata,update_fail_htlc,reason,byte,len",
    "msgtype,update_fail_malformed_htlc,135",
    "msgdata,update_fail_malformed_htlc,channel_id,channel_id,",
    "msgdata,update_fail_malformed_htlc,id,u64,",
    "msgdata,update_fail_malformed_htlc,sha256_of_onion,sha256,",
    "msgdata,update_fail_malformed_htlc,failure_code,u16,",
    "msgtype,commitment_signed,132",
    "msgdata,commitment_signed,channel_id,channel_id,",
    "msgdata,commitment_signed,signature,signature,",
    "msgdata,commitment_signed,num_htlcs,u16,",
    "msgdata,commitment_signed,htlc_signature,signature,num_htlcs",
    "msgtype,revoke_and_ack,133",
    "msgdata,revoke_and_ack,channel_id,channel_id,",
    "msgdata,revoke_and_ack,per_commitment_secret,byte,32",
    "msgdata,revoke_and_ack,next_per_commitment_point,point,",
    "msgtype,update_fee,134",
    "msgdata,update_fee,channel_id,channel_id,",
    "msgdata,update_fee,feerate_per_kw,u32,",
    "msgtype,channel_reestablish,136",
    "msgdata,channel_reestablish,channel_id,channel_id,",
    "msgdata,channel_reestablish,next_commitment_number,u64,",
    "msgdata,channel_reestablish,next_revocation_number,u64,",
    "msgdata,channel_reestablish,your_last_per_commitment_secret,byte,32",
    "msgdata,channel_reestablish,my_current_per_commitment_point,point,",
]
