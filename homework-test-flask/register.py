from flask import Flask, request
from flask_restful import Resource, Api
from flask_cors import CORS

app = Flask(__name__)
cors = CORS(app, resources={r"/api/*": {"origins": "*"}})
api = Api(app)


class User:
    def __init__(self, username, phone, password):
        self.username = username
        self.phone = phone
        self.password = password

    def checkUsername(self):
        return len(self.username) >= 4

    def checkPhone(self):
        return len(self.phone) == 11 and self.phone.isdecimal()

    def checkPassword(self):
        if len(self.password) < 8 or self.password.isdecimal() or self.password.isalpha():
            return False
        continuousFlag = True
        notContinuousCount = 0
        for i in range(1, len(self.password)):
            if abs(ord(self.password[i - 1]) - ord(self.password[i])) > 1:
                notContinuousCount += 1
            else:
                notContinuousCount = 0
            if notContinuousCount >= 2:
                continuousFlag = False
                break
        return not continuousFlag

    def check(self):
        return self.checkUsername() and self.checkPhone() and self.checkPassword()


class UserController(Resource):
    def post(self):
        data = request.get_json(force=True)
        user = User(data['username'], data['phone'], data['password'])
        if user.check():
            return {"success": "pass"}, 201
        else:
            return {"error": "invalid user info"}, 400


api.add_resource(UserController, '/api/user')

if __name__ == '__main__':
    app.run(debug=True)
