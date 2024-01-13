/**
 * SEE Solutions
 * Author: ac@dpdl.io
 * 
 * This class is part of the Dpdl example 'app/getnews/dpdlGetNews2.h' and is used as input/output for json.decode(..)
 */
package dpdl.dpdlLibs;

public class StoryTest {
	public int id;
	public String title;
	public String url;
	public int[] kids;
	
	public StoryTest() {
		id = 0;
		title = "null";
		url = "null";
		kids = new int[] {};
	}
	
	public void setId(int id) {
		this.id = id;
	}
	
	public int getId() {
		return id;
	}

	public void setTitle(String title) {
		this.title = title;
	}
	
	public String getTitle() {
		return title;
	}
	
	public void setUrl(String url) {
		this.url = url;
	}
	
	public String getUrl() {
		return url;
	}
	
	
	public void setKids(int[] kids) {
		this.kids = kids;
	}
	
	public int[] getKids() {
		return kids;
	}
}
