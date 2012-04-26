package com.hoveritu.vertex;
/**
 * @author Sorush Arefipour
 */
public class Vertex {
	private String lon;
	private String lat;
	/**
	 * Constructor that is called if an object of this class being created
	 * @param lon
	 * @param lat
	 */
	public Vertex(String lat, String lon){
		this.lon = lon;
		this.lat = lat;
	}
	public String getLon() {
		return lon;
	}
	public void setLon(String lon) {
		this.lon = lon;
	}
	public String getLat() {
		return lat;
	}
	public void setLat(String lat) {
		this.lat = lat;
	}
}
