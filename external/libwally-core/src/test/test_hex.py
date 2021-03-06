import unittest
from util import *

class HexTests(unittest.TestCase):

    def test_hex_verify(self):
        # Valid inputs
        self.assertEqual(wally_hex_verify(utf8('00')), WALLY_OK)

        # Bad inputs
        self.assertEqual(wally_hex_verify(None),       WALLY_EINVAL) # NULL hex
        self.assertEqual(wally_hex_verify(''),         WALLY_EINVAL) # Empty hex
        self.assertEqual(wally_hex_verify(utf8('a')),  WALLY_EINVAL) # Odd length input
        self.assertEqual(wally_hex_verify(utf8('xy')), WALLY_EINVAL) # Non-hex

        self.assertEqual(wally_hex_n_verify(None, 2),       WALLY_EINVAL) # NULL hex
        self.assertEqual(wally_hex_n_verify(utf8('00'), 0), WALLY_EINVAL) # 0 Length
        self.assertEqual(wally_hex_n_verify(utf8('00'), 1), WALLY_EINVAL) # Odd Length

    def test_hex_to_bytes(self):
        LEN = 4
        buf, buf_len = make_cbuffer('00' * LEN)

        for i in range(256):
            for s in ("%02X" % i, "%02x" % i): # Upper/Lower
                hex_ = utf8(s * LEN)
                ret, written = wally_hex_to_bytes(hex_, buf, buf_len)
                self.assertEqual((ret, written), (WALLY_OK, LEN))
                ret, written = wally_hex_n_to_bytes(hex_, len(hex_), buf, buf_len)
                self.assertEqual((ret, written), (WALLY_OK, LEN))

        # Bad inputs
        for (s, b, l) in [(None,        buf,  buf_len),
                          (utf8('00'),  None, buf_len),
                          (utf8('000'), buf,  buf_len),
                          (utf8('00'),  buf,  0)]:
            ret, written = wally_hex_to_bytes(s, b, l)
            self.assertEqual((ret, written), (WALLY_EINVAL, 0))
            ret, written = wally_hex_n_to_bytes(s, len(s) if s else 0, b, l)
            self.assertEqual((ret, written), (WALLY_EINVAL, 0))

        for l in (1,    # Too small, returns the required length
                  LEN): # Too large, returns length written
            ret, written = wally_hex_to_bytes(utf8('0000'), buf, l)
            self.assertEqual((ret, written), (WALLY_OK, 2))

        # Empty string
        ret, written = wally_hex_to_bytes(utf8(''), buf, buf_len)
        self.assertEqual((ret, written), (WALLY_OK, 0))


    def test_hex_from_bytes(self):
        LEN = 4

        for i in range(256):
            s = "%02x" % i * LEN
            buf, buf_len = make_cbuffer(s)
            ret, retstr = wally_hex_from_bytes(buf, buf_len)
            self.assertEqual((ret, retstr), (WALLY_OK, s))

        # Bad input
        ret, written = wally_hex_from_bytes(None, buf_len)
        self.assertEqual((ret, written), (WALLY_EINVAL, None))

        # Empty buffer
        ret, written = wally_hex_from_bytes(buf, 0)
        self.assertEqual((ret, written), (WALLY_OK, ''))


if __name__ == '__main__':
    unittest.main()
