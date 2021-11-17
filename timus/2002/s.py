users = {}
logged_in = set()

n = int(input())
for i in range(n):
    parts = input().split()
    if parts[0] == "register":
        if parts[1] in users:
            print("fail: user already exists")
        else:
            users[parts[1]] = parts[2]
            print("success: new user added")
    elif parts[0] == "login":
        if parts[1] not in users:
            print("fail: no such user")
        elif parts[2] != users[parts[1]]:
            print("fail: incorrect password")
        elif parts[1] in logged_in:
            print("fail: already logged in")
        else:
            logged_in.add(parts[1])
            print("success: user logged in")
    elif parts[0] == "logout":
        if parts[1] not in users:
            print("fail: no such user")
        elif parts[1] not in logged_in:
            print("fail: already logged out")
        else:
            logged_in.remove(parts[1])
            print("success: user logged out")

