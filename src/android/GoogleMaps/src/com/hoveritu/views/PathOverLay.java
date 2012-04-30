package com.hoveritu.views;
/**
 * @author Sorush Arefipour
 */
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Path;
import android.graphics.Point;

import com.google.android.maps.GeoPoint;
import com.google.android.maps.MapView;
import com.google.android.maps.Overlay;
import com.google.android.maps.Projection;

public class PathOverLay extends Overlay{	 
	GeoPoint gP1;
	GeoPoint gP2;

	/**
	 * Constructor that called when an object of this class is being created
	 */
	public PathOverLay(GeoPoint gP1, GeoPoint gP2){ 
		this.gP1 = gP1;
		this.gP2 = gP2;
	} 

	/**
	 * Draw the selected canvas over the map
	 */
	public void draw(Canvas canvas, MapView mapv, boolean shadow){
		super.draw(canvas, mapv, shadow);
		Paint mPaint = new Paint();	 
		Projection projection = mapv.getProjection(); 
		mPaint.setDither(true); 
		mPaint.setColor(Color.RED); 
		mPaint.setStyle(Paint.Style.FILL_AND_STROKE); 
		mPaint.setStrokeJoin(Paint.Join.ROUND); 
		mPaint.setStrokeCap(Paint.Cap.ROUND); 
		mPaint.setStrokeWidth(4); 

		Point p1 = new Point(); 
		Point p2 = new Point();	 
		Path path = new Path();	 
		projection.toPixels(gP1, p1); 
		projection.toPixels(gP2, p2); 

		int x1 = p1.x;
		int y1 = p1.y;
		int x2 = p2.x;
		int y2 = p2.y;

		path.moveTo(x1, y1); 
		path.lineTo(x2, y2);	 
		canvas.drawPath(path, mPaint); 
	}	
}