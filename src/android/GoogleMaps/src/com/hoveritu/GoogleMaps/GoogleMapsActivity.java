package com.hoveritu.GoogleMaps;

/**
 * @author Sorush Arefipour
 */

import java.util.ArrayList;

import com.hoveritu.views.PathOverLay;
import com.hoveritu.vertex.Vertex;
import com.google.android.maps.GeoPoint;
import com.google.android.maps.MapActivity;
import com.google.android.maps.MapView;
import android.os.Bundle;
import android.view.View;
import android.widget.LinearLayout;
 
public class GoogleMapsActivity extends MapActivity 
{    
    MapView mapView; 
    public static ArrayList<Vertex> vertices = new ArrayList<Vertex>();
    
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) 
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        initMap();
        showPath();
 
    }
    
    /**
	 * set up map and adding zoom control on it
	 */
	private void initMap() {
		mapView = (MapView) findViewById(R.id.mapView);
		@SuppressWarnings("deprecation")
		View zoomView = mapView.getZoomControls();
		LinearLayout myzoom = (LinearLayout) findViewById(R.id.zoom);
		myzoom.addView(zoomView);
		mapView.displayZoomControls(true);
	}
    
	private void showPath() {
//		vertices = Gustav.vertices
		
/**		Sample points
		Vertex a1 = new Vertex("57.706348","11.935251");
		Vertex a2 = new Vertex("57.706062","11.936367");
		Vertex a3 = new Vertex("38.61687","-79.628906");
		vertices.add(a1);
		vertices.add(a2);
		vertices.add(a3);
*/


		for (int i = 1; i < vertices.size(); i++){

			String lat = vertices.get(i).getLat();
			String lon = vertices.get(i).getLon();
			String lat2 = vertices.get(i-1).getLat();
			String lon2 = vertices.get(i-1).getLon();
		
		
			Double Dlat1 = new Double(Double.parseDouble(lat)*1E6);
			Double Dlng1 = new Double(Double.parseDouble(lon)*1E6);
			Double Dlat2 = new Double(Double.parseDouble(lat2)*1E6);
			Double Dlng2 = new Double(Double.parseDouble(lon2)*1E6);
			
			GeoPoint gP1 = new GeoPoint(Dlat1.intValue(),Dlng1.intValue()); 
			GeoPoint gP2 = new GeoPoint(Dlat2.intValue(),Dlng2.intValue());
		
			// draw the path on the map
			mapView.getOverlays().add(new PathOverLay(gP1,gP2));
			mapView.invalidate();
			mapView.getController();
			}
	}
 
    @Override
    protected boolean isRouteDisplayed() {
        // TODO Auto-generated method stub
        return false;
    }
}