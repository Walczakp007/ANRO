#include "ros/ros.h"
#include "std_msgs/String.h"
#include <stdio.h>
#include "anro1/mapMessage.h"
#include <cstdlib>
#include <visualization_msgs/Marker.h>
using namespace std;

class MapOfCity{
  
  public:
  
  MapOfCity()
  {
      sendCrossroadsInfo();
      sendMapVisualization();             
  };
  
  
  void sendMapVisualization()
  {

     // funkcja do drogi
        
        ros::NodeHandle n;
	ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 10);
	visualization_msgs::Marker points, line_strip;
        ros::Rate loop_rate(10000);
  	
	while (ros::ok())
  	{
       	    
	    visualization_msgs::Marker points, line_strip, line_list;
            points.header.frame_id = line_strip.header.frame_id = line_list.header.frame_id = "/my_frame";
    	    points.header.stamp = line_strip.header.stamp = line_list.header.stamp = ros::Time::now();
    	    points.ns = line_strip.ns = line_list.ns = "MapOfCity";
    	    points.action = line_strip.action = line_list.action = visualization_msgs::Marker::ADD;
   	    points.pose.orientation.w = line_strip.pose.orientation.w = line_list.pose.orientation.w = 1.0;



        points.id = 0;
    	line_strip.id = 1;
    	line_list.id = 2;



   	points.type = visualization_msgs::Marker::POINTS;
    	line_strip.type = visualization_msgs::Marker::LINE_STRIP;
     	line_list.type = visualization_msgs::Marker::LINE_LIST;



    // POINTS markers use x and y scale for width/height respectively
    	points.scale.x = 0.2;
    	points.scale.y = 0.2;

    // LINE_STRIP/LINE_LIST markers use only the x component of scale, for the line width
    	line_strip.scale.x = 0.05;
    	line_list.scale.x = 0.1;



    // Points are green
   	 points.color.b = 1.0f;
   	 points.color.a = 1.0;

    // Line strip is blue
   	 line_strip.color.b = 1.0;
    	line_strip.color.a = 1.0;

 



    // Create the vertices for the points and lines
    for (uint32_t i = 0; i < 150; ++i)
    {
      
      float y = 50;
      float z = 0.00;
      geometry_msgs::Point p;
      p.x = (int32_t)i;
      p.y = y;
      p.z = z;

      points.points.push_back(p);
      line_strip.points.push_back(p);

    }


    marker_pub.publish(points);
    marker_pub.publish(line_strip);
   
    

    for (uint32_t i = 50; i < 100; ++i)
    {
      
      float x = 150;
      float z = 0.000;
      geometry_msgs::Point p;
      p.x = x;
      p.y = (int32_t)i;
      p.z = z;

      points.points.push_back(p);
      line_strip.points.push_back(p);

    }


    marker_pub.publish(points);
    marker_pub.publish(line_strip);
   
    
   for (uint32_t i = 150; i > 100; --i)
    {
      
      float y = 100;
      float z = 0.000;
      geometry_msgs::Point p;
      p.x = (int32_t)i;
      p.y = y;
      p.z = z;

      points.points.push_back(p);
      line_strip.points.push_back(p);

    }


    marker_pub.publish(points);
    marker_pub.publish(line_strip);
  
    for (uint32_t i = 100; i > 0; --i)
    {
      
      float x = 100;
      float z = 0.000;
      geometry_msgs::Point p;
      p.x = x;
      p.y = (int32_t)i;
      p.z = z;

      points.points.push_back(p);
      line_strip.points.push_back(p);

    }


    marker_pub.publish(points);
    marker_pub.publish(line_strip);

    for (uint32_t i = 100; i > 50; --i)
    {
      
      float y = 0;
      float z = 0.000;
      geometry_msgs::Point p;
      p.x = (int32_t)i;
      p.y = y;
      p.z = z;

      points.points.push_back(p);
      line_strip.points.push_back(p);

    }


    marker_pub.publish(points);
    marker_pub.publish(line_strip);

    for (uint32_t i = 0; i < 100; ++i)
    {
      
      float x = 50;
      float z = 0.000;
      geometry_msgs::Point p;
      p.x = x;
      p.y = (int32_t)i;
      p.z = z;

      points.points.push_back(p);
      line_strip.points.push_back(p);

    }


    marker_pub.publish(points);
    marker_pub.publish(line_strip);


    for (uint32_t i = 50; i > 0; --i)
    {
      
      float y = 100;
      float z = 0.000;
      geometry_msgs::Point p;
      p.x = (int32_t)i;
      p.y = y;
      p.z = z;

      points.points.push_back(p);
      line_strip.points.push_back(p);

    }


    marker_pub.publish(points);
    marker_pub.publish(line_strip);

    for (uint32_t i = 100; i > 50; --i)
    {
      
      float x = 0;
      float z = 0.000;
      geometry_msgs::Point p;
      p.x = 0;
      p.y = (int32_t)i;
      p.z = z;

      points.points.push_back(p);
      line_strip.points.push_back(p);

    }


    marker_pub.publish(points);
    marker_pub.publish(line_strip);

   loop_rate.sleep();
   }
     
  }
  
  // metoda sendCrossroadsInfo wysyła w topicu map_info message mapMessage zawierajace pola okreslajace polozenie oraz typ skrzyzownia/zakretu
  void sendCrossroadsInfo()
  {      
         //konfiguracja polaczenia
         ros::NodeHandle n;
         ros::Publisher map_info = n.advertise<anro1::mapMessage>("map_info", 1000);
         anro1::mapMessage crossroad1;
         anro1::mapMessage turning;
         
         //petla czeka okolo 10sek na listener
         ros::Rate loop_rate(10);
         
         ROS_INFO("I heard: ");
         // wysylanie informacji o polozeniu skrzyzowan
        
         // czekaj poki nie bedzie trzech subskrypji (lights, turns, model)
         while (map_info.getNumSubscribers() < 1 )
    	 {
      		
      	       ROS_WARN_ONCE("Please create a subscriber to the marker");
         	loop_rate.sleep();
        }
        
        int counter=1;
        ROS_WARN_ONCE("Subscribed");
        while(counter>0)
           {
                counter--; 
                ROS_INFO("I heard: ");
	         
	         crossroad1.x = 50 ;
	         crossroad1.y = 50 ;
	         crossroad1.type = "fourLanes";
	         map_info.publish(crossroad1);
         
	         crossroad1.x = 100 ;
	         crossroad1.y = 50 ;
	         crossroad1.type = "fourLanes";
	         map_info.publish(crossroad1);


                 turning.x = 150 ;
	         turning.y = 50 ;
	         turning.type = "turningUpLeft";
	         map_info.publish(turning);

                 turning.x = 150 ;
	         turning.y = 100 ;
	         turning.type = "turningDownLeft";
	         map_info.publish(turning);
	         
                 turning.x = 100 ;
	         turning.y = 100 ;
	         turning.type = "turningDownRight";
	         map_info.publish(turning); 

                 turning.x = 100 ;
	         turning.y = 0 ;
	         turning.type = "turningUpLeft";
	         map_info.publish(turning); 
                
	         turning.x = 50 ;
	         turning.y = 0 ;
	         turning.type = "turningUpRight";
	         map_info.publish(turning);   
	         
	                     
	         
	         turning.x = 50 ;
	         turning.y = 100 ;
	         turning.type = "turningDownLeft";
	         map_info.publish(turning);     
	         
	         turning.x = 0 ;
	         turning.y = 100 ;
	         turning.type = "turningDownRight";
	         map_info.publish(turning);  
	       
	         turning.x = 0 ;
	         turning.y = 50 ;
	         turning.type = "turningUpRight";
	         map_info.publish(turning);  
                 loop_rate.sleep();
	}
	         
  }

};



int main(int argc, char** argv)
{
  ros::init(argc, argv, "MapOfCity");
  new MapOfCity();
  ROS_INFO("Exiting..");
  return 0;
}