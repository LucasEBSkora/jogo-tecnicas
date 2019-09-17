#ifndef EVENTREPORT_H
#define EVENTREPORT_H

namespace FISW {
  
  class EventReport {
  
  private:
  public:
    bool closeGame;
    bool errorHappened; 
    float passedTime; 

    EventReport();
    ~EventReport();
  };

  
} 


#endif
