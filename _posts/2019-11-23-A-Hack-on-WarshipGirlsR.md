---
title: A Little Hack on the game Warship Girls R
date: 2019-11-23
categories:
    - tech
tags:
    - hack
    - life
    - game
    - web
---

Thanks to a recent historical movie regarding the infamous World War II sea battle, [_Midway_][midway-movie], 
I have picked up a game that I dropped right before the university started.
Not only that, 
I also had a chance to reorganize some notes I wrote for the game and built a [sub-site][warship-site] for those "long-forgotten" notes.

A quick introduction to those who never heard of Warship Girls R (WGR):
it is a [kancolle][kancolle-wiki]-like game with a series of local modifications for Chinese players.
Although as much as I enjoy playing WGR, I do not recommend this type of game for my post readers.
Simply because {my post readers} ∩ {target audience of WGR} = ∅
(I am 99% sure the equation works; prove me wrong if you find kancolle-like game interests you).

Now back to the main purpose of this post: why am I hacking this game?
After I returned to this game, I found the game brought up a new and stupid system (kitchen system).
The stupid numerical design of the system pushed me for an alternate solution.

I wrote a script.

The purpose of the script was to
(1) login one of my alternate accounts (this can scale up to hundreds of accounts);
(2) perform one task in the new system (order a menu in the kitchen).

The first thing was to figure out how does the game communicate between local clients and the server,
so that I can mimic the behaviour of a real user.
After some research, I found that the game uses straightforward HTTP/HTTPS protocol.
I then found a [post][1] that uses [Fiddler][2] to monitor all connections between devices and the Web.
Through some testing, I documented all critical URLs and Hosts for my script. What left are just coding!

Followings are some snippets of the script.

A normal mean of login:

```
    def login(self, username, pwd, server):
        url_login = self.hm_login_server + "1.0/get/login/@self"
        data = {
            "platform": "0",
            "appid": "0",
            "app_server_type": "0",
            "password": pwd,
            "username": username
        }

        self.refresh_headers(url_login)

        login_response = session.post(url=url_login, data=json.dumps(data).replace(" ", ""),
                                      headers=self.pastport_headers, timeout=10).text
        login_response = json.loads(login_response)

        if "error" in login_response and int(login_response["error"]) != 0:
            return False

        tokens = ""
        if "access_token" in login_response:
            tokens = login_response["access_token"]
        if "token" in login_response:
            tokens = login_response["token"]

        url_init = self.hm_login_server + "1.0/get/initConfig/@self"
        self.refresh_headers(url_init)
        session.post(url=url_init, data="{}", headers=self.pastport_headers, timeout=10)
        time.sleep(1)

        # Validate token
        while True:
            url_info = self.hm_login_server + "1.0/get/userInfo/@self"

            login_data = json.dumps({"access_token": tokens})

            self.refresh_headers(url_info)
            user_info = session.post(url=url_info, data=login_data, headers=self.pastport_headers, timeout=10).text
            user_info = json.loads(user_info)
            if "error" in user_info and user_info["error"] != 0:
                tokens = ""
                continue
            else:
                break

        login_url = self.login_server + "index/hmLogin/" + tokens + self.get_url_end()
        login_response = session.get(url=login_url, headers=HEADER, timeout=10)
        login_text = json.loads(zlib.decompress(login_response.content))

        self.cookies = login_response.cookies.get_dict()
        self.uid = str(login_text['userId'])
        return login_text
```

Encrypting timestamps: 

```
    def encryption(self, url, method):
        times = datetime.datetime.utcnow().strftime('%a, %d %b %Y %H:%M:%S GMT')
        data = str(method) + "\n" + times + "\n" + "/" + url.split("/", 3)[-1]
        mac = hmac.new(self.key.encode(), data.encode(), hashlib.sha1)
        data = mac.digest()
        return base64.b64encode(data).decode("utf-8"), times
```

The task I wanted to perform (order a menu in the kitchen):

```
    def get_friend_list(self):
        url = self.server_list[0]["host"] + 'friend/getlist' + self.get_url_end()
        raw_data = self.decompress_data(url)
        data = json.loads(raw_data)
        return data["list"]
    
    def friend_feat(self, uid, cook_item):
        url = self.server_list[0]["host"] + 'live/feat/' + uid + '/' + cook_item + self.get_url_end()
        raw_data = self.decompress_data(url)
        data = json.loads(raw_data)
        return data
```

Ta da. That's it. If you are interested for the full source code, check it [here][3].
Since I need to run the script daily (and I am too lazy to run it myself), a `cronjob` was set up as well.

Using the scripts, I estimated that I can achieve my desired goal in the game in just 3 months, instead of 5 years (told you, the numerical design is stupid)!

Thanks for reading ;)


[midway-movie]: https://www.imdb.com/title/tt6924650/
[warship-site]: https://warship.yanqing-wu.com
[kancolle-wiki]: https://en.wikipedia.org/wiki/Kantai_Collection
[1]: https://renqiancheng.com/2019/01/Fiddler-%E5%AE%89%E5%8D%93%E6%89%8B%E6%9C%BA%E6%8A%93%E5%8C%85%E6%95%99%E7%A8%8B.html
[2]: https://www.telerik.com/fiddler
[3]: https://git.io/JePLz