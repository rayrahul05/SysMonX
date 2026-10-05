#include "SignalHandler.h"
#include <csignal>
namespace{volatile std::sig_atomic_t flag=0; void handler(int){flag=1;}}
void SignalHandler::install(){std::signal(SIGINT,handler);std::signal(SIGTERM,handler);}
bool SignalHandler::stopRequested(){return flag!=0;}
