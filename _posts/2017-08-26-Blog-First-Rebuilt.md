---
title: First Fully Rebuilt Of The Site
date: 2017-08-26
categories:
    - blog
tags:
    - PWYQ Space
    - Cloudflare
    - Jekyll
    - HTTPs
---

Now, it was actually two weeks ago since my site had been fully rebuilt, yet, I haven't wrote a single post.
"Um-huh, this is not good. People will go to a blog site for meaningful posts, not for the code behind the site." I thought to myself.
Right, I thus fi--nally force myself to wrote down the first post after rebuilding.

#### Why rebuilt?

To answer this question, I'd like to talk about *why built this site at the first place*. 
The site was initially built during the last Christmas week. Winter time, boring me. 
It was also the last long break for me before looking for my first co-op in the coming spring term, and a simple personal blog was the only project I could think of which can be done in one week.
Besides, I had almost zero experience on front-end tech at that time; building a site was a perfect opportunity to practise that. 
In addition, I always want a small playground that belongs to myself to document interesting stuff. 
Therefore, this site was born.

Before started building this site, I made a simple but rather strict rule: **Build without any templates**, meaning that I need to code all by myself, no copy-paste.
This rule eventually became one of the potential factors of the first rebuilt.

I did obey the rule, until reality changed my mind.

Due to the restriction rule and limited project time, I concentrated on the structure of this site, rather fancy styles.
With a lot of hard work, the initial version of this site cost less than 30 hours to be online, and it had almost all elements a blog site needed.
For instance, I could easily write a post with `Markdown`; or easily add a sub-page in the Menu bar by creating a corresponding `*.html` file and modifying `*.yml` file.
Also, Google Analytics and Disqus were implemented on my site. Ah, It just looked perfect to me. 

You can tell I was very proud of my first web project at that time.

And, I proudly added this project to my resume, along with a line-following music player robot project, an [Android app][2] done at EC-Hacks and an object tracking algorithm for [UWRT][1] Mars Rover.
All projects were completed after I entering University of Waterloo while I maintaining my GPA at an excellent level.
Look at that time-management, that execution.
Honestly, I thought I was able to work at some big-name tech companies.

And, I proudly submitted my resume to those tech giants, even with some in USA.

Nonetheless, I had merely TWO interviews. 
I started to look for a reason.
Maybe my projects just look "naive" to those sophisticated HRs who already read millions of resumes;
maybe I am an international student;
maybe my resume is not attractive
......
maybe my website looks like a crap!

Yes, my website did look like a crap at that time; I admit that, cause it didn't have many elaborate and fancy `css` styles!
I believed this might not be the decisive reason why I got rejected, but must be one of the major ones.
From there, I decided to rebuild my website with a fancy theme and implement some localized modifications.
Yet I delayed the rebuilt again and again until the last month of my first co-op as I became a bit lazy in this summer :) .

#### New tech in the rebuilt

##### Custom Domain

I bought a domain at GoDaddy, and hosted DNS on Cloudflare.


1. Go to one of domain companies, search for your favourite domain name, purchase it if it's available.

    I chose [GoDaddy][3]. No particular preference, it's just cheaper than other ones, and convenient.

2. Create a `CNAME` file and add it to your git repository.

    The `CNAME` filename has no extensions. 
    Inside the file, there will be only one line of code, which is your custom domain. Take my website domain as example:
    
    ```
    www.pwyqspace.com
    ```

3. Go to [Cloudflare][4]

    Create an account if you haven't got one.
    Cloudflare is free for personal use, and it's enough for a blog site.
    Next, you should see a page like `Set up Websites`.
    ![alt text][5]
    Enter your domain name in the blank and click `Begin Scan`.
    It will automatically add your domain name after successfully scanning your domain records.
    (This may take about 1 minute)
    
4. Edit the IP addresses records

    **Note**: following only works for `Github Page` project. 
    
    Go to `DNS` tab in the top menu bar.
    Add following two `A` type records in `IPV4 address` with your domain in the `Name`:
    ```
    192.30.252.153
    192.30.252.154
    ```
    Then, add a `CNAME` type with `www` as `Name`, and your original domain as `Domain name`.
    When it's done, the page should look like this:
    ![alt text][6]
    
5. Get name servers

    Then following the detailed instruction on Cloudflare to get your name servers.
    It should automatically assign you two nameservers.
    
6. Go Back to your domain company and change nameservers

    Since I use GoDaddy, I will use GoDaddy as example.
    
    Go to `My Account` -> `My Products` -> `Domains`-> `DNS`.
    Then change the default nameservers to those which Cloudflare assigned you.

7. Be patient

    Your new domain name may not be effective immediately.
    In fact, it may take as long as one day to allow your new domain into use.

8. Don't forget to update Comment, Share, Analytics site data

    Since you started using a new domain, you need to update your old one to the new one.
    For example, update your old domain name to current one at `Disqus`, `Google Analytics` and `AddThis` (if you use any of those).

##### Using HTTPs Protocol

Using HTTPs protocol has lots of advantages:

- [Provide a more secured channel between your browser and visited website][8]
- [HTTPs is faster than HTTP (thanks to SPDY)][9]
- [HTTPS is a SEO ranking signal][10]

A detailed instruction can be found at this post: [Using HTTPs with Custom Domain Name on GitHub Pages][11].
Following the tutorial, my final `page rules` hosted on Cloudflare looks like this:
![alt text][7]

##### Custom fonts

As you may noticed, the font of `PWYQ Space` logo and my 404 page looks quite different (yes, it's not a pic).

- First, go to some font website.
- Then, download some fonts you like that are free for personal-use.
- Next, create a test file with all downloaded fonts. If you don't know how to use custom fonts, look at [Using a custom (ttf) font in CSS][12].
- Last step, compare all fonts and choose one that best suits you theme or need.

##### WebStorm
[WebStorm Download Link][14]

Almost forgot this one XD.
WebStorm is a great tool for front-end development. Strongly recommended.

I still remember how I built my first version of website.
I coded everything in Notepad at first; no IDE was involved.
Though I switched to Sublime and Vim later, still not saving my coding efficiency.
Moreover, I didn't know to use `localhost` or any local simulations.
So, every time I changed a bit `css` file or `html` page, I needed to commit to Github.
Then, eagerly refreshed the page and waited to see the compiled result on browser.
If you go to my earlier commit history, you can find a lot of useless commits like `test` or `modify`.
What a waste of time!

Thanks to Webstorm, my every commit counts now.

#### Extra Notes

Through the process of rebuilding, I found some interesting questions/concepts to consider or new technology to use in the future:

- [Cache-Control][15]
- [What's the difference between Cache-Control: max-age=0 and no-cache?][16]
- [The Django template language][17]
- [JSHint, A Static Code Analysis Tool for JavaScript][18]
- [Why some css file is in one line of text][19]
- [A/B Testing][20]
- PostgreSQL
- MEAN (MongoDB, Express, Angular, Node.js)
- Socket.io


#### End Thought

My first rebuilt of the site came earlier than it ought to be.
I once thought I would have a 100% self-built site, but this fragile dream only lasted half-year.
But hey, thank you, ruthless reality, you also contributed to my first rebuilt :)

I just started looking forward to a second rebuilt.
By then, what my mindset and programming level will be?

<div style="text-align: right"> At Waterloo, 11:02 PM </div>


[1]: http://uwrobotics.uwaterloo.ca/
[2]: https://devpost.com/software/journe-0mo4wg
[3]: https://ca.godaddy.com/
[4]: https://www.cloudflare.com/

[5]: /assets/images/posts/Blog-First-Rebuilt/add_website.png "Cloudflare - scan website record"
[6]: /assets/images/posts/Blog-First-Rebuilt/add_DNS_records.png "Cloudflare - add DNS record"
[7]: /assets/images/posts/Blog-First-Rebuilt/page-rules.png "Cloudflare - add page rules"

[8]: http://mashable.com/2011/05/31/https-web-security/#bm91Jt9Fe5qm
[9]: https://samrueby.com/2015/01/26/why-is-https-faster-than-http/
[10]: https://webmasters.googleblog.com/2014/08/https-as-ranking-signal.html
[11]: https://www.jonathan-petitcolas.com/2017/01/13/using-https-with-custom-domain-name-on-github-pages.html
[12]: https://stackoverflow.com/questions/7512468/using-a-custom-ttf-font-in-css

[13]: http://jshint.com/about/
[14]: https://www.jetbrains.com/webstorm/

[15]: https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/Cache-Control
[16]: https://stackoverflow.com/questions/1046966/whats-the-difference-between-cache-control-max-age-0-and-no-cache
[17]: https://docs.djangoproject.com/en/1.11/
[18]: http://jshint.com/about/
[19]: https://github.com/eddiemachado-zz/bones/issues/265
[20]: https://www.optimizely.com/ab-testing/