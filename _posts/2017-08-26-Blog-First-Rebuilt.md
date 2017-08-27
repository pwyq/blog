---
title: PWYQ Space First Rebuilt!
date: 2017-08-26
categories:
    - posts
tags:
    - pwyq's Space
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
All projects were completed after I entered university of waterloo while I maintaining my GPA at an excellent level. Honestly, I thought I was able to work at some big-name tech companies.

And, I proudly submitted my resume to those tech giants, even with some in USA.

Nonetheless, I had merely TWO interviews. 
I started to look for a reason.
Maybe my projects just look "naive" to those sophisticated HRs who already read millions of resumes;
maybe I am an international student;
maybe my resume is not attractive
......
maybe my website looks like a crap!

Yes, my website did look like a crap at that time.
I believed this might not be the decisive reason why I got rejected, but must be one of the major ones.
From there, I decided to rebuild my website with a fancy theme and implement some localized modifications.
Yet I delayed the rebuilt again and again until the last month of my first co-op as I became a bit lazy in this summer :) .

#### New tech in the rebuilt

**Note**: following only works for `Github Page` project. 

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
    It will automatically add your domain name after successfully scanning your doamin records.
    (This may take about 1 minute)
    
4. Edit the IP addresses records

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


Thanks to following tutorials

https://www.chenhuijing.com/blog/setting-up-custom-domain-github-pages/




[1]: http://uwrobotics.uwaterloo.ca/
[2]: https://devpost.com/software/journe-0mo4wg
[3]: https://ca.godaddy.com/
[4]: https://www.cloudflare.com/
[5]: /assets/images/posts/Blog-First-Rebuilt/add_website.png "Cloudflare scan website record"
[6]: /assets/images/posts/Blog-First-Rebuilt/add_DNS_records.png "Cloudflare add DNS record"