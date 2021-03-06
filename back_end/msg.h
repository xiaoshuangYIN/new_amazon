#include "protocal/amazon_orig_3.pb.h"
#include "protocal/AmazonUPS.pb.h"

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/text_format.h>

#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <stdint.h>
#include <string>
/*
struct _load{
  uint32_t whNum;
  uint64_t shipId;
  uint32_t truckId;
};
typedef struct _load load;
*/
/* send message and receive is seperated */
template<typename T> bool sendMesgTo(const T & , google::protobuf::io::FileOutputStream *);
template<typename T> bool recvMesgFrom(T & , google::protobuf::io::FileInputStream * );

bool send_AConnect(uint64_t , int);
bool send_AConnect_recv_AConnected(uint64_t worldid,  google::protobuf::io::FileOutputStream * outfile, google::protobuf::io::FileInputStream * infile);

bool send_APack(uint32_t whnum, uint64_t shipId, std::vector<std::unordered_map<std::string, std::string> >& prods, int sockfd );
bool send_APurchaseMore(uint32_t , std::vector<std::unordered_map<std::string, std::string> > &, int );
bool send_simspeed(uint32_t speed, int sockfd);

bool send_APutOnTruck(int sockfd, std::vector<std::unordered_map<std::string, std::string> > loads);

void parse_AResponses(AResponses Ares, std::vector<int>& readys, std::vector<int>& loadeds, std::vector<std::pair<int, std::vector<std::unordered_map<std::string, std::string> > > >& arriveds);
bool recv_parse_AResponse(int sockfd,  std::vector<int>& readys, std::vector<int>& loadeds, std::vector<std::pair<int, std::vector<std::unordered_map<std::string, std::string> > > >& arriveds);

bool send_ACon(int socket, int worldid);
// u
bool send_UConnect_recv_UConnected(uint64_t worldid,  google::protobuf::io::FileOutputStream * outfile, google::protobuf::io::FileInputStream * UPS_in);
