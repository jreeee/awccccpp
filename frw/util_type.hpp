#ifndef UTIL_TYPE_HPP
#define UTIL_TYPE_HPP


#include <string>
#include <vector>
namespace util {
namespace type {

// ========== taken from the Anilist GraphQL docs ==========

// idk if these are even helpful, but it seemed important to have them

enum class MediaSource {
    ORIGINAL, // An original production not based of another work
    MANGA, // Asian comic book
    LIGHT_NOVEL,    // Written work published in volumes
    VISUAL_NOVEL,   // Video game driven primary by text and narrative
    VIDEO_GAME,     // Video game
    OTHER,          // Other
    NOVEL,          // Version 2+ only. Written works not published in volumes
    DOUJINSHI,      // Version 2+ only. Self-published works
    ANIME,          // Version 2+ only. Japanese Anime
    WEB_NOVEL,      // Version 3 only. Written works published online
    LIVE_ACTION,    // Version 3 only. Live action media such as movies or TV show
    GAME,           // Version 3 only. Games excluding video games
    COMIC,          // Version 3 only. Comics excluding manga
    MULTIMEDIA_PROJECT, // Version 3 only. Multimedia project
    PICTURE_BOOK    // Version 3 only. Picture book
};

enum class MediaSeason {
    WINTER, // Months December to February
    SPRING, // Months March to May
    SUMMER, // Months June to August
    FALL,   // Months September to November
};

enum class MediaType {
    ANIME, // Japanese Anime
    MANGA, // Asian comic
};

enum class MediaFormat {
    TV,         // Anime broadcast on television
    TV_SHORT,   // Anime which are under 15 minutes in length and broadcast on television
    MOVIE,      // Anime movies with a theatrical release
    SPECIAL,    // Special episodes that have been included in DVD/Blu-ray releases, picture dramas, pilots, etc
    OVA,        // (Original Video Animation) Anime that have been released directly on DVD/Blu-ray without originally going through a theatrical release or television broadcast
    ONA,        // (Original Net Animation) Anime that have been originally released online or are only available through streaming services.
    MUSIC,      // Short anime released as a music video
    MANGA,      // Professionally published manga with more than one chapter
    NOVEL,      // Written books released as a series of light novels
    ONE_SHOT    // Manga with just one chapter
};

enum class MediaStatus {
    FINISHED,       // Has completed and is no longer being released
    RELEASING,      // Currently releasing
    NOT_YET_RELEASED, // To be released at a later date
    CANCELLED,      // Ended before the work could be finished
    HIATUS,         // Version 2 only. Is currently paused from releasing and will resume at a later date
};

enum class MediaSort {
    ID,
    ID_DESC,
    TITLE_ROMAJI,
    TITLE_ROMAJI_DESC,
    TITLE_ENGLISH,
    TITLE_ENGLISH_DESC,
    TITLE_NATIVE,
    TITLE_NATIVE_DESC,
    TYPE,
    TYPE_DESC,
    FORMAT,
    FORMAT_DESC,
    START_DATE,
    START_DATE_DESC,
    END_DATE,
    END_DATE_DESC,
    SCORE,
    SCORE_DESC,
    POPULARITY,
    POPULARITY_DESC,
    TRENDING,
    TRENDING_DESC,
    EPISODES,
    EPISODES_DESC,
    DURATION,
    DURATION_DESC,
    STATUS,
    STATUS_DESC,
    CHAPTERS,
    CHAPTERS_DESC,
    VOLUMES,
    VOLUMES_DESC,
    UPDATED_AT,
    UPDATED_AT_DESC,
    SEARCH_MATCH,
    FAVOURITES,
    FAVOURITES_DESC,
};

// Tags get updated somewhat regularly, something like this should do
// { MediaTagCollection{ id, name, category, isAdult }}
// create Tags and Categorys based on that 
// should be a singleton, idk if i bother with that tho

struct MediaTagLayout {
    const int id;
    const std::string name;
    const int category_index;
    const bool is_adult;
};

class MediaTag {
  public:
    std::vector<MediaTagLayout> tags;
    std::vector<std::string> categories;
    static MediaTag& getInstance();
    //MediaTag(MediaTag const&) = delete;
    // void operator=(MediaTag const&) = delete;
  private:
    int checkCategory(std::string const& category);
    MediaTag();
};

// should not need to be updated, get via GenreCollection
class MediaGenre {
    const std::vector<std::string> genres;
};

// this file is still missing stuff like StaffSort and the like 

} // end namespace type
} // end namespace util
#endif