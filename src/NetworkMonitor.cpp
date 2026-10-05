#include "NetworkMonitor.h"
#include <fstream>
#include <sstream>
#include <string>
std::vector<NetworkInterfaceInfo> NetworkMonitor::interfaces() const { std::ifstream f("/proc/net/dev"); std::vector<NetworkInterfaceInfo> r; std::string line; while(std::getline(f,line)){ auto c=line.find(':'); if(c==std::string::npos) continue; auto name=line.substr(0,c); auto p=name.find_first_not_of(" \t"); if(p!=std::string::npos) name=name.substr(p); std::istringstream s(line.substr(c+1)); std::uint64_t rx{},a{},b{},d{},e{},g{},h{},i{},tx{},j{},k{},l{},m{},n{},o{},q{}; if(s>>rx>>a>>b>>d>>e>>g>>h>>i>>tx>>j>>k>>l>>m>>n>>o>>q) r.push_back({name,rx,tx}); } return r; }
