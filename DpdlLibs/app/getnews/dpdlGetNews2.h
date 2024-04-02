# File: app/getnews/dpdlGetNews2.h
#
# Example: Download top 10 story news via json http get requests. Data is decoded and stored in a native java object via getter and setter.
#		   The java class 'StoryTest' has already been compiled and added in the class definition file. The sources are in the same folder.
#
# Author: A.Costa
# e-mail: info@dpdl.io
#
#

import('http')
import('json')


# main
string stories_url   = "https://hacker-news.firebaseio.com/v0/topstories.json"
string item_base_url = "https://hacker-news.firebaseio.com/v0/item/"

println("downloading news...")

string resp = http.getraw(stories_url)

raise(resp, "Error in downloading data")

object jsonobj = json.parse(resp, 0)
ids[] = array(jsonobj)

string story_url
object storyobj = loadObj("StoryTest")

int c = 0
for(c < 10)
	println("---------------------------------------------------------------------")

	story_url = item_base_url + ids[c] + ".json"
	resp = http.getraw(story_url)

	raise(resp, "Error in downloading story")

	storyobj = json.decode(resp, storyobj)

	println("id: " + storyobj.id)
	println("title: " + storyobj.title)
	println("url: " + storyobj.url)

	c = c+1
endfor

println("finished!")
