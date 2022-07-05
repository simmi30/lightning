lightning-waitinvoice -- Command for waiting for specific payment
=================================================================

SYNOPSIS
--------

**waitinvoice** *label*

DESCRIPTION
-----------

The **waitinvoice** RPC command waits until a specific invoice is paid,
then returns that single entry as per **listinvoice**.

RETURN VALUE
------------

[comment]: # (GENERATE-FROM-SCHEMA-START)
On success, an object is returned, containing:
- **label** (string): unique label supplied at invoice creation
- **description** (string): description used in the invoice
- **payment_hash** (hash): the hash of the *payment_preimage* which will prove payment (always 64 characters)
- **status** (string): Whether it's paid or expired (one of "paid", "expired")
- **expires_at** (u64): UNIX timestamp of when it will become / became unpayable
- **amount_mbro** (mbro, optional): the amount required to pay this invoice
- **bolt11** (string, optional): the BOLT11 string (always present unless *bolt12* is)
- **bolt12** (string, optional): the BOLT12 string (always present unless *bolt11* is)

If **status** is "paid":
  - **pay_index** (u64): Unique incrementing index for this payment
  - **amount_received_mbro** (mbro): the amount actually received (could be slightly greater than *amount_mbro*, since clients may overpay)
  - **paid_at** (u64): UNIX timestamp of when it was paid
  - **payment_preimage** (secret): proof of payment (always 64 characters)

[comment]: # (GENERATE-FROM-SCHEMA-END)

On error the returned object will contain `code` and `message` properties,
with `code` being one of the following:

- -32602: If the given parameters are wrong.
- -1: If the invoice is deleted while unpaid, or the invoice does not exist.
- 903: If the invoice expires before being paid, or is already expired.

AUTHOR
------

Christian Decker <<decker.christian@gmail.com>> is mainly
responsible.

SEE ALSO
--------

lightning-waitanyinvoice(7), lightning-listinvoice(7),
lightning-delinvoice(7), lightning-invoice(7)

RESOURCES
---------

Main web site: <https://github.com/ElementsProject/lightning>

[comment]: # ( SHA256STAMP:6e16a7d6292dbec346a785f6347da4d47b49d0d9773d7d2acf713b176c5be153)