import json
import unittest
from register import app


class RegisterTest(unittest.TestCase):
    def setUp(self):
        self.client = app.test_client()

    def test_username(self):
        success = [
            {"username": "test", "phone": "15078142365", "password": "r3322dhn"},
            {"username": "qwerqwrqwe", "phone": "15078142365", "password": "r3322dhn"},
            {"username": "tesewqt", "phone": "15078142365", "password": "r3322dhn"},
        ]
        fail = [
            {"username": "t", "phone": "15078142365", "password": "r3322dhn"},
            {"username": "12", "phone": "15078142365", "password": "r3322dhn"},
            {"username": "qwe", "phone": "15078142365", "password": "r3322dhn"},
            {"username": "", "phone": "15078142365", "password": "r3322dhn"},
        ]
        for i in success:
            ret = self.client.post("/api/user", data=json.dumps(i))
            self.assertEqual(ret.status_code, 201, i)
        for i in fail:
            ret = self.client.post("/api/user", data=json.dumps(i))
            self.assertEqual(ret.status_code, 400, i)

    def test_phone(self):
        success = [
            {"username": "test", "phone": "15078142365", "password": "r3322dhn"},
            {"username": "test", "phone": "51201151545", "password": "r3322dhn"},
            {"username": "test", "phone": "95945102212", "password": "r3322dhn"},
        ]
        fail = [
            {"username": "test", "phone": "1507842365", "password": "r3322dhn"},
            {"username": "test", "phone": "150781402365", "password": "r3322dhn"},
            {"username": "test", "phone": "1", "password": "r3322dhn"},
            {"username": "test", "phone": "", "password": "r3322dhn"},
            {"username": "test", "phone": "dsaddasddas", "password": "r3322dhn"},
            {"username": "test", "phone": "ds322aesdas", "password": "r3322dhn"},
            {"username": "test", "phone": "122asdda112", "password": "r3322dhn"},
        ]
        for i in success:
            ret = self.client.post("/api/user", data=json.dumps(i))
            self.assertEqual(ret.status_code, 201, i)
        for i in fail:
            ret = self.client.post("/api/user", data=json.dumps(i))
            self.assertEqual(ret.status_code, 400, i)

    def test_password(self):
        success = [
            {"username": "test", "phone": "15078142365", "password": "2151214a"},
            {"username": "test", "phone": "15078142365", "password": "da5dsax1"},
            {"username": "test", "phone": "15078142365", "password": "dsadfasfsdfdsasfd1aasd"},
            {"username": "test", "phone": "15078142365", "password": "454545645611a15154848"},
        ]
        fail = [
            {"username": "test", "phone": "15078142365", "password": "adsab2d"},
            {"username": "test", "phone": "15078142365", "password": "212121d"},
            {"username": "test", "phone": "15078142365", "password": "1"},
            {"username": "test", "phone": "15078142365", "password": ""},
            {"username": "test", "phone": "15078142365", "password": "abdsajdbasjjdbasjbdjas"},
            {"username": "test", "phone": "15078142365", "password": "5648564561561156315454"},
            {"username": "test", "phone": "15078142365", "password": "abcd1234"},
            {"username": "test", "phone": "15078142365", "password": "abcdcba123321"},
        ]
        for i in success:
            ret = self.client.post("/api/user", data=json.dumps(i))
            self.assertEqual(ret.status_code, 201, i)
        for i in fail:
            ret = self.client.post("/api/user", data=json.dumps(i))
            self.assertEqual(ret.status_code, 400, i)


if __name__ == '__main__':
    unittest.main(verbosity=2)
