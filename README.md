###  Disclaimer: this project is neither affiliated with [AniList](https://anilist.co) nor [AWC](https://anilist.co/user/AWC/)

###  Disclaimer 2: This is currently non-functional as i am working on building up the structure first
## awccccpp / aw4cpp

aw4cpp (AWC Challenge Checker C++) is a redesign of my older project [awccc](https://github.com/jreeee/awccc).


## goal

similar to awccc, aw4cpp aims to help you fill out AWC Challenges by adding dates and cheking if chosen entries fit their given requirement. additionally i want to implement a overview that displays the progress for all open challenges.

## why rewrite and not fix the old app?

awccc is written in Python and was more like a proof of concept than a proper application. with that the overall design of the app more or less hacked together. while it _generally_ works there are some big limitations e.g. being rather slow, checking only card-links, and a couple more.

with aw4cpp i want to design my software _properly_ and have a fast and reliable tool for my challenging endeavours.

## dependencies

this app **includes** two libraries:
- [curlpp](http://www.curlpp.org/) which **requires libcurl**
- [nlohmann's json](https://github.com/nlohmann/json)

i might add a GraphQL lib, but for now that's it

## build

i plan to include executables when this is in a better shape...

```
$ mkdir build && cd build
$ make 
```

## next steps
now that i have the first steps for the general structure, coming up are:

**prio**
- have it build on linux and windows (idk about mac)
- storing a basic config with the username
- creating a list of all (currently available) challenges
- retrieving the users anime list (for now just the "Completed")
- retrieve the created challenge posts
- simple CLI interface that shows the progress for challenges based on entries added (and completed)
- set up proper chaching for all the data required

**soon**

- figure out license stuff
- retrieving and parsing the completed challenges from awc.moe
- create a ruleset for all (available) challenges
- modify a challenge post by adding all the dates


**at some point**

- parse challenge posts and check with challenge rules
- parse reqs and check with AL
- generate a overview of all challenges, similar to [the gist i use](https://gist.github.com/jreeee/28f314b3f0984777e3303c4f687c5ba0) mb with html and a bit nicer

**endgoal**
- can automatically backfill challenges
- can recommend stuff for reqs
