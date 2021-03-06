// Generated for ALMemory version 1.14

#ifndef ALMEMORYPROXYREMOTE_H_
#define ALMEMORYPROXYREMOTE_H_
#include <alremoteproxies/almemoryproxyposthandlerremote.h>

namespace AL
{

/// <summary>ALMemory provides a centralized memory that can be used to store and retrieve named values. It also acts as a hub for the distribution of event notifications.</summary>
class ALMemoryProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    ALMemoryProxyRemote(std::string pIP, int pPort) : ALProxyRemote("ALMemory", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALMemoryProxyPostHandlerRemote post;


    /// <summary>
    /// Declares an event to allow future subscriptions to the event
    /// </summary>
    /// <param name="eventName"> The name of the event </param>
    void declareEvent(const std::string& eventName)
    {

        callVoidRemote("declareEvent" , eventName);
    }


    /// <summary>
    /// Declares an event to allow future subscriptions to the event
    /// </summary>
    /// <param name="eventName"> The name of the event </param>
    /// <param name="extractorName"> The name of the extractor capable of creating the event </param>
    void declareEvent(const std::string& eventName, const std::string& extractorName)
    {

        callVoidRemote("declareEvent" , eventName, extractorName);
    }


    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    void exit()
    {

        callVoidRemote("exit");
    }


    /// <summary>
    /// Gets the name of the parent broker.
    /// </summary>
    /// <returns> The name of the parent broker. </returns>
    std::string getBrokerName()
    {

        return callRemote<std::string >("getBrokerName");
    }


    /// <summary>
    /// Gets the value of a key-value pair stored in memory
    /// </summary>
    /// <param name="key"> Name of the value. </param>
    /// <returns> The data as an ALValue. This can often be cast transparently into the original type. </returns>
    AL::ALValue getData(const std::string& key)
    {

        return callRemote<AL::ALValue >("getData" , key);
    }


    /// <summary>
    /// DEPRECATED - Gets the value of a key-value pair stored in memory. Please use the version of this method with no second parameter.
    /// </summary>
    /// <param name="key"> Name of the value. </param>
    /// <param name="deprecatedParameter"> DEPRECATED - This parameter has no effect, but is left for compatibility reason. </param>
    /// <returns> The data as an ALValue </returns>
    AL::ALValue getData(const std::string& key, const int& deprecatedParameter)
    {

        return callRemote<AL::ALValue >("getData" , key, deprecatedParameter);
    }


    /// <summary>
    /// Gets a list of all key names that contain a given string
    /// </summary>
    /// <param name="filter"> A string used as the search term </param>
    /// <returns> A list of all the data key names that contain the given string. </returns>
    std::vector<std::string> getDataList(const std::string& filter)
    {

        return callRemote<std::vector<std::string> >("getDataList" , filter);
    }


    /// <summary>
    /// Gets the key names for all the key-value pairs in memory
    /// </summary>
    /// <returns> A list containing the keys in memory </returns>
    std::vector<std::string> getDataListName()
    {

        return callRemote<std::vector<std::string> >("getDataListName");
    }


    /// <summary>
    /// DEPRECATED - Blocks the caller until the value of a key changes
    /// </summary>
    /// <param name="key"> Name of the data. </param>
    /// <param name="deprecatedParameter"> DEPRECATED - this parameter has no effect </param>
    /// <returns> an array containing all the retrieved data </returns>
    AL::ALValue getDataOnChange(const std::string& key, const int& deprecatedParameter)
    {

        return callRemote<AL::ALValue >("getDataOnChange" , key, deprecatedParameter);
    }




    /// <summary>
    /// Descriptions of all given keys
    /// </summary>
    /// <param name="keylist"> List of keys. (empty to get all descriptions) </param>
    /// <returns> an array of tuple (name, type, description) describing all keys. </returns>
    AL::ALValue getDescriptionList(const std::vector<std::string>& keylist)
    {

        return callRemote<AL::ALValue >("getDescriptionList" , keylist);
    }


    /// <summary>
    /// Get data value and timestamp
    /// </summary>
    /// <param name="key"> Name of the variable </param>
    /// <returns> A list of all the data key names that contain the given string. </returns>
    AL::ALValue getEventHistory(const std::string& key)
    {

        return callRemote<AL::ALValue >("getEventHistory" , key);
    }


    /// <summary>
    /// Gets a list containing the names of all the declared events
    /// </summary>
    /// <returns> A list containing the names of all events </returns>
    std::vector<std::string> getEventList()
    {

        return callRemote<std::vector<std::string> >("getEventList");
    }


    /// <summary>
    /// Gets the list of all events generated by a given extractor
    /// </summary>
    /// <param name="extractorName"> The name of the extractor </param>
    /// <returns> A list containing the names of the events associated with the given extractor </returns>
    std::vector<std::string> getExtractorEvent(const std::string& extractorName)
    {

        return callRemote<std::vector<std::string> >("getExtractorEvent" , extractorName);
    }


    /// <summary>
    /// Gets the values associated with the given list of keys. This is more efficient than calling getData many times, especially over the network.
    /// </summary>
    /// <param name="keyList"> An array containing the key names. </param>
    /// <returns> An array containing all the values corresponding to the given keys. </returns>
    AL::ALValue getListData(const AL::ALValue& keyList)
    {

        return callRemote<AL::ALValue >("getListData" , keyList);
    }


    /// <summary>
    /// Retrieves a method's description.
    /// </summary>
    /// <param name="methodName"> The name of the method. </param>
    /// <returns> A structure containing the method's description. </returns>
    AL::ALValue getMethodHelp(const std::string& methodName)
    {

        return callRemote<AL::ALValue >("getMethodHelp" , methodName);
    }


    /// <summary>
    /// Retrieves the module's method list.
    /// </summary>
    /// <returns> An array of method names. </returns>
    std::vector<std::string> getMethodList()
    {

        return callRemote<std::vector<std::string> >("getMethodList");
    }


    /// <summary>
    /// Gets a list containing the names of all the declared micro events
    /// </summary>
    /// <returns> A list containing the names of all the microEvents </returns>
    std::vector<std::string> getMicroEventList()
    {

        return callRemote<std::vector<std::string> >("getMicroEventList");
    }


    /// <summary>
    /// Retrieves the module's description.
    /// </summary>
    /// <returns> A structure describing the module. </returns>
    AL::ALValue getModuleHelp()
    {

        return callRemote<AL::ALValue >("getModuleHelp");
    }


    /// <summary>
    /// Gets a list containing the names of subscribers to an event.
    /// </summary>
    /// <param name="name"> Name of the event or micro-event </param>
    /// <returns> List of subscriber names </returns>
    std::vector<std::string> getSubscribers(const std::string& name)
    {

        return callRemote<std::vector<std::string> >("getSubscribers" , name);
    }


    /// <summary>
    /// Get data value and timestamp
    /// </summary>
    /// <param name="key"> Name of the variable </param>
    /// <returns> A list of all the data key names that contain the given string. </returns>
    AL::ALValue getTimestamp(const std::string& key)
    {

        return callRemote<AL::ALValue >("getTimestamp" , key);
    }


    /// <summary>
    /// Gets the storage class of the stored data. This is not the underlying POD type.
    /// </summary>
    /// <param name="key"> Name of the variable </param>
    /// <returns> String type: Data, Event, MicroEvent </returns>
    std::string getType(const std::string& key)
    {

        return callRemote<std::string >("getType" , key);
    }


    /// <summary>
    /// Gets the method usage string. This summarises how to use the method.
    /// </summary>
    /// <param name="name"> The name of the method. </param>
    /// <returns> A string that summarises the usage of the method. </returns>
    std::string getUsage(const std::string& name)
    {

        return callRemote<std::string >("getUsage" , name);
    }


    /// <summary>
    /// Inserts a key-value pair into memory, where value is an int
    /// </summary>
    /// <param name="key"> Name of the value to be inserted. </param>
    /// <param name="value"> The int to be inserted </param>
    void insertData(const std::string& key, const int& value)
    {

        callVoidRemote("insertData" , key, value);
    }


    /// <summary>
    /// Inserts a key-value pair into memory, where value is a float
    /// </summary>
    /// <param name="key"> Name of the value to be inserted. </param>
    /// <param name="value"> The float to be inserted </param>
    void insertData(const std::string& key, const float& value)
    {

        callVoidRemote("insertData" , key, value);
    }


    /// <summary>
    /// Inserts a key-value pair into memory, where value is a string
    /// </summary>
    /// <param name="key"> Name of the value to be inserted. </param>
    /// <param name="value"> The string to be inserted </param>
    void insertData(const std::string& key, const std::string& value)
    {

        callVoidRemote("insertData" , key, value);
    }


    /// <summary>
    /// Inserts a key-value pair into memory, where value is an ALValue
    /// </summary>
    /// <param name="key"> Name of the value to be inserted. </param>
    /// <param name="data"> The ALValue to be inserted. This could contain a basic type, or a more complex array. See the ALValue documentation for more information. </param>
    void insertData(const std::string& key, const AL::ALValue& data)
    {

        callVoidRemote("insertData" , key, data);
    }


    /// <summary>
    /// Inserts a list of key-value pairs into memory.
    /// </summary>
    /// <param name="list"> An ALValue list of the form [[Key, Value],...]. Each item will be inserted. </param>
    void insertListData(const AL::ALValue& list)
    {

        callVoidRemote("insertListData" , list);
    }


    /// <summary>
    /// Returns true if the method is currently running.
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <returns> True if the method is currently running </returns>
    bool isRunning(const int& id)
    {

        return callRemote<bool >("isRunning" , id);
    }


    /// <summary>
    /// Just a ping. Always returns true
    /// </summary>
    /// <returns> returns true </returns>
    bool ping()
    {

        return callRemote<bool >("ping");
    }


    /// <summary>
    /// Publishes the given data to all subscribers.
    /// </summary>
    /// <param name="name"> Name of the event to raise. </param>
    /// <param name="value"> The data associated with the event. This could contain a basic type, or a more complex array. See the ALValue documentation for more information. </param>
    void raiseEvent(const std::string& name, const AL::ALValue& value)
    {

        callVoidRemote("raiseEvent" , name, value);
    }


    /// <summary>
    /// Publishes the given data to all subscribers.
    /// </summary>
    /// <param name="name"> Name of the event to raise. </param>
    /// <param name="value"> The data associated with the event. This could contain a basic type, or a more complex array. See the ALValue documentation for more information. </param>
    void raiseMicroEvent(const std::string& name, const AL::ALValue& value)
    {

        callVoidRemote("raiseMicroEvent" , name, value);
    }


    /// <summary>
    /// Removes a key-value pair from memory
    /// </summary>
    /// <param name="key"> Name of the data to be removed. </param>
    void removeData(const std::string& key)
    {

        callVoidRemote("removeData" , key);
    }


    /// <summary>
    /// Removes a micro event from memory and unsubscribes any exiting subscribers.
    /// </summary>
    /// <param name="name"> Name of the event to remove. </param>
    void removeMicroEvent(const std::string& name)
    {

        callVoidRemote("removeMicroEvent" , name);
    }


    /// <summary>
    /// Describe a key
    /// </summary>
    /// <param name="name"> Name of the key. </param>
    /// <param name="description"> The description of the event (text format). </param>
    void setDescription(const std::string& name, const std::string& description)
    {

        callVoidRemote("setDescription" , name, description);
    }


    /// <summary>
    /// returns true if the method is currently running
    /// </summary>
    /// <param name="id"> the ID of the method to wait for </param>
    void stop(const int& id)
    {

        callVoidRemote("stop" , id);
    }


    /// <summary>
    /// Subscribes to an event and automaticaly launches the module that declared itself as the generator of the event if required.
    /// </summary>
    /// <param name="name"> The name of the event to subscribe to </param>
    /// <param name="callbackModule"> Name of the module to call with notifications </param>
    /// <param name="callbackMethod"> Name of the module's method to call when a data is changed </param>
    void subscribeToEvent(const std::string& name, const std::string& callbackModule, const std::string& callbackMethod)
    {

        callVoidRemote("subscribeToEvent" , name, callbackModule, callbackMethod);
    }


    /// <summary>
    /// DEPRECATED Subscribes to event and automaticaly launches the module capable of generating the event if it is not already running. Please use the version without the callbackMessage parameter.
    /// </summary>
    /// <param name="name"> The name of the event to subscribe to </param>
    /// <param name="callbackModule"> Name of the module to call with notifications </param>
    /// <param name="callbackMessage"> DEPRECATED Message included in the notification. </param>
    /// <param name="callbacMethod"> Name of the module's method to call when a data is changed </param>
    void subscribeToEvent(const std::string& name, const std::string& callbackModule, const std::string& callbackMessage, const std::string& callbacMethod)
    {

        callVoidRemote("subscribeToEvent" , name, callbackModule, callbackMessage, callbacMethod);
    }


    /// <summary>
    /// Subscribes to a microEvent. Subscribed modules are notified on theircallback method whenever the data is updated, even if the new value is the same as the old value.
    /// </summary>
    /// <param name="name"> Name of the data. </param>
    /// <param name="callbackModule"> Name of the module to call with notifications </param>
    /// <param name="callbackMessage"> Message included in the notification. This can be used to disambiguate multiple subscriptions. </param>
    /// <param name="callbackMethod"> Name of the module's method to call when a data is changed </param>
    void subscribeToMicroEvent(const std::string& name, const std::string& callbackModule, const std::string& callbackMessage, const std::string& callbackMethod)
    {

        callVoidRemote("subscribeToMicroEvent" , name, callbackModule, callbackMessage, callbackMethod);
    }


    /// <summary>
    /// Does nothing. DEPRECATED.
    /// </summary>
    /// <param name="moduleName">  </param>
    void unregisterModuleReference(const std::string& moduleName)
    {

        callVoidRemote("unregisterModuleReference" , moduleName);
    }


    /// <summary>
    /// Unsubscribes a module from the given event. No further notifications will be received.
    /// </summary>
    /// <param name="name"> The name of the event </param>
    /// <param name="callbackModule"> The name of the module that was given when subscribing. </param>
    void unsubscribeToEvent(const std::string& name, const std::string& callbackModule)
    {

        callVoidRemote("unsubscribeToEvent" , name, callbackModule);
    }


    /// <summary>
    /// Unsubscribes from the given event. No further notifications will be received.
    /// </summary>
    /// <param name="name"> Name of the event. </param>
    /// <param name="callbackModule"> The name of the module that was given when subscribing. </param>
    void unsubscribeToMicroEvent(const std::string& name, const std::string& callbackModule)
    {

        callVoidRemote("unsubscribeToMicroEvent" , name, callbackModule);
    }


    /// <summary>
    /// Returns the version of the module.
    /// </summary>
    /// <returns> A string containing the version of the module. </returns>
    std::string version()
    {

        return callRemote<std::string >("version");
    }


    /// <summary>
    /// Wait for the end of a long running method that was called using 'post'
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <param name="timeoutPeriod"> The timeout period in ms. To wait indefinately, use a timeoutPeriod of zero. </param>
    /// <returns> True if the timeout period terminated. False if the method returned. </returns>
    bool wait(const int& id, const int& timeoutPeriod)
    {

        return callRemote<bool >("wait" , id, timeoutPeriod);
    }


};

}
#endif // ALMEMORYPROXY_H_
