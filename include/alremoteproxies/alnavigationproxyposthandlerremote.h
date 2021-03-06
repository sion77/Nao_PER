// Generated for ALNavigation version 1.14


#ifndef ALNAVIGATIONPROXYPOSTHANDLERREMOTE_H_
#define ALNAVIGATIONPROXYPOSTHANDLERREMOTE_H_
#include <alremotecall/alremoteproxy.h>

namespace AL
{
class ALNavigationProxyRemote;

/// <summary>Use ALNavigation module to make the robot go safely to the asked pose2D.</summary>
class ALNavigationProxyPostHandlerRemote : public ALProxyRemote
{
    friend class ALNavigationProxyRemote;

    protected:
        AL::ALProxyRemote* fParent;

    private:
        void setParent(AL::ALProxyRemote* pParent) { fParent = pParent;}

  public:

    /// <summary>
    /// Use ALNavigation module to make the robot go safely to the asked pose2D.
    /// ALNavigationPostHandlerRemote gives acces to all bound methods of the module, using a thread around each call.
    /// Long running tasks can be stopped by calling stop(id) with the id returned by the post.
    /// </summary>
    ALNavigationProxyPostHandlerRemote() : fParent(NULL)
    {}



    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int exit()
    {
      return fParent->pCall("exit");
    }










    /// <summary>
    /// Distance in meters fromwhich the robot should stop if there is an obstacle.
    /// </summary>
    /// <param name="arg1"> arg </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int setSecurityDistance(const float& arg1)
    {
      return fParent->pCall("setSecurityDistance" , arg1);
    }

    /// <summary>
    /// returns true if the method is currently running
    /// </summary>
    /// <param name="id"> the ID of the method to wait for </param>
    /// <returns> brokerTaskID : The ID of the task assigned to it by the broker. </returns>
    int stop(const int& id)
    {
      return fParent->pCall("stop" , id);
    }



};

}
#endif // ALNAVIGATIONPROXYPOSTHANDLERREMOTE_H_

