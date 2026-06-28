# File: app/getnews/dpdlGetNews.h
#
# Example: Download top 10 story news via json http get requests. Data is decoded and stored in a struct
#
# Author: A.Costa
# e-mail: info@dpdl.io
#
#

import('http')
import('json')

struct Story {
	int id
	string title
	string url
}

# main
string stories_url   = "https://hacker-news.firebaseio.com/v0/topstories.json"
string item_base_url = "https://hacker-news.firebaseio.com/v0/item/"

println("downloading news...")

string resp = http.getraw(stories_url)

raise(resp, "Error in downloading data")

object jsonobj = json.parse(resp, 0)
ids[] = array(jsonobj)

string story_url
struct Story storyobj

int i = 0
for(i < 10)
	println("---------------------------------------------------------------------")

	story_url = item_base_url + ids[i] + ".json"
	resp = http.getraw(story_url)

	raise(resp, "Error in downloading story")

	storyobj = json.decode(resp, storyobj)

	println("id: " + storyobj.id + " is of type: " + typeof(storyobj.id))
	println("title: " + storyobj.title + " is of type: " + typeof(storyobj.title))
	println("url: " + storyobj.url + " is of type: " + typeof(storyobj.url))

	i=i+1
endfor

println("finished!")

