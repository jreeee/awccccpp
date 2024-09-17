## structure documentation

### cached files
initial mockup:

```~/.config/aw4cpp```

- user.json

```~/.cache/aw4cpp```
- al-cache
    - tags.json
    - anime.json
    - manga.json
    - staff.json (?)
- awc-cache
    - challenge-rules
        - *challenge_id*-rule.json
    - challenges
        - *challenge_id*-obj.json
    - codes
        - *challenge_id*-code.json
    - lists
        - (each community list)
- *username*-cache
    - challenges
        - *challenge_id*-post-*instance*.json
    - unique-codes
        - *challenge_id*-code.json
    - awc-profile.json
    - lists
        - anime-complete.json
        - manga-complete.json
        - anime-planning.json ...
    - updated-challenges
        - *challenge_name*-*timestamp*.json

### cached file info | update cycle
- ```user.json``` username(s), preferences | offline
- ```al-cache/tags.json``` tag names, tag ids, is adult, tag categories | rare
- ```al-cache/*``` various types of info relating to the category | when needed
- ```awc-cache/challenge-rules/*``` generated rule-objects | when needed/release
- ```al-cache/challenges/*``` generated challenge objects | when needed/release
- ```al-cache/codes/*``` provided standard codes | when needed/release
- ```al-cache/lists/*``` all the community lists | medium, auto
- ```u-cache/``` generated for each user in the _user.json_
- ```u-cache/challenges/*``` all (non-completed?) challenge posts | when needed/release
- ```u-cache/unique-codes/*``` special challenge codes | when-needed
- ```u-cache/awc-profile.json``` extracted challenger profile | auto medium/often
- ```u-cache/lists/*``` lists for both mediums (? custom lists) | medium/when checking
- ```u-cache/updated-challenges/*``` generated challenge codes | auto (when checking)


This is still very much wip, tho i feel like this is a solid start