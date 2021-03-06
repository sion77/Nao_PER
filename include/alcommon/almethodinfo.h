/**
 * @author Aldebaran Robotics
 * Copyright (c) Aldebaran Robotics 2007, 2011 All Rights Reserved
 */

/** @file
 *  @brief
 */

#pragma once
#ifndef _LIBALCOMMON_ALCOMMON_ALMETHODINFO_H_
#define _LIBALCOMMON_ALCOMMON_ALMETHODINFO_H_

# include <alcommon/alparamtype.h>
# include <boost/shared_ptr.hpp>


# define BLOCKINGFUNCTION     0 /**< Functions are synchronous  */
# define ASYNCHRONOUSFUNCTION 1 /**< Functions are asynchronous  */

namespace AL
{
  class ALFunctorBase;

  /**
   * \class ALMethodInfo almethodinfo.h "alcommon/almethodinfo.h"
   * \brief ALMethodInfo is the introspection container.
   *
   *        We store method description, return type, argument list, examples...
   * \ingroup Proxy
   * \ingroup Module
   */
  class ALMethodInfo
  {
  public:
    /** \brief Default constructor. */
    ALMethodInfo() {
      mask = 0;
    }

    /** \brief Default destructor. */
    virtual ~ALMethodInfo() {}

    /**
     * \enum methodOption
     * \brief methodOption is differents option for the method.
     */
    enum methodOption {
      CPPMethod           = 1, /**< C++ method. */
      AsynchronousMethod  = 2, /**< Asynchronous method. */
      localMethod         = 4  /**< Local method. */
    };

  /**
   * \class ALParameterInfo almethodinfo.h "alcommon/almethodinfo.h"
   * \brief ALParameterInfo is the introspection container.
   */
    class ALParameterInfo
    {
    public:
      std::string paramError;  /**< */
      std::string name;        /**< Parameter's name. */
      std::string description; /**< Parameter's description. */
      std::string strType;     /**< Parameter's type name. */
      bool        optional;    /**< True if it is an optional parameter. */
    };

  /**
   * \class ALParameterInfoOptional almethodinfo.h "alcommon/almethodinfo.h"
   * \brief ALParameterInfoOptional is the option container.
   */
    template <typename T>
    class ALParameterInfoOptional: public ALParameterInfo {
    public:
      /**
       * \brief Default contructor.
       * \param defaultValue new optional paramater
       */
      ALParameterInfoOptional(T defaultValue) {
        m_defaultValue = defaultValue;
      }
      T m_defaultValue; /**< Optional parameter. */
    };

  /**
   * \class ALExample almethodinfo.h "alcommon/almethodinfo.h"
   * \brief ALExample is container for example.
   */
    class ALExample {
    public:
      std::string language;   /**< Example's language. */
      std::string strExample; /**< Example. */
    };

    std::string                      moduleName;        /**< Module name. */
    std::string                      methodName;        /**< Method name. */
    std::string                      methodDescription; /**< Method description. */
    std::vector<ALParameterInfo>     parameters;        /**< Method parameters. */
    std::string                      returnValue;       /**< Method return value. */
    std::vector<ALExample>           examples;          /**< Method example. */
    boost::shared_ptr<ALFunctorBase> ptrOnMethod;       /**< Pointer on the mehotd. */
    ALParameterInfo                  returnInfo;        /**< Info about the return  */
    short                            mask;              /**< Method options. */


    /**
     * \brief Check is the method is used for C++.
     * \return true if it's a C++ the method, flase otherwise
     */
    bool isCpp(void) {
      return ((mask & CPPMethod) == CPPMethod);
    }

    /**
     * \brief Check is the method is used as asynchronous one.
     * \return true if it's a asynchronous method, flase otherwise
     */
    bool isAsynchronous(void) {
      return (mask & AsynchronousMethod) > 0 ? true: false;
    }

    /**
     * \brief Check is the method is a local one.
     * \return true if it's a local method, flase otherwise
     */
    bool isLocalMethod(void) {
      return ((mask & localMethod) == localMethod);
    }

    /**
     * \brief Add method option.
     * \param pOption new option
     */
    void addOption(int pOption)
    {
      mask = mask | (short)pOption;
    }

    /**
     * \brief Get a pointer to the method.
     * \return a pointer to the method
     */
    ALFunctorBase* getFunction() {
      return ptrOnMethod.get();
    }

    /**
     * \brief Clear parameters and examples.
     */
    void clear(void) {
      parameters.clear();
      examples.clear();
    }
  };

  template <typename C, typename R>
  void completeAndCheck(R(C::*) (), ALMethodInfo & pDesc)
  {
    pDesc.returnInfo.strType = getParamStrType<R>();
  }

  template <typename C, typename P1, typename R>
  void completeAndCheck(R(C::*) (P1), ALMethodInfo & pDesc)
  {
    pDesc.returnInfo.strType = getParamStrType<R>();
    ALMethodInfo::ALParameterInfo param;
    param.description = "arg";
    std::string name = "arg0";
    for (int i = pDesc.parameters.size(); i < 1; ++i) {
      name[3] = (char) (i + '1');
      param.name = name;
      pDesc.parameters.push_back(param);
    }
    pDesc.parameters[0].strType =  getParamStrType<P1>();
  }

  template <typename C, typename P1, typename P2, typename R>
  void completeAndCheck(R(C::*) (P1, P2), ALMethodInfo & pDesc)
  {
    pDesc.returnInfo.strType = getParamStrType<R>();
    ALMethodInfo::ALParameterInfo param;
    std::string name = "arg0";
    param.description = "arg";
    for (int i = pDesc.parameters.size() ; i < 2; ++i) {
      name[3] = (char) (i + '1');
      param.name  = name;
      pDesc.parameters.push_back(param);
    }
    pDesc.parameters[0].strType =  getParamStrType<P1>();
    pDesc.parameters[1].strType =  getParamStrType<P2>();
  }

  template <typename C, typename P1, typename P2, typename P3, typename R>
  void completeAndCheck(R(C::*) (P1, P2, P3), ALMethodInfo & pDesc)
  {
    pDesc.returnInfo.strType = getParamStrType<R>();
    ALMethodInfo::ALParameterInfo param;
    std::string name = "arg0";
    param.description = "arg";
    for (int i = pDesc.parameters.size(); i < 3; ++i) {
      name[3] = i + '1';
      param.name = name;
      pDesc.parameters.push_back(param);
    }
    pDesc.parameters[0].strType =  getParamStrType<P1>();
    pDesc.parameters[1].strType =  getParamStrType<P2>();
    pDesc.parameters[2].strType =  getParamStrType<P3>();
  }

  template <typename C, typename P1, typename P2, typename P3, typename P4, typename R>
  void completeAndCheck(R(C::*) (P1, P2, P3, P4), ALMethodInfo & pDesc)
  {
    pDesc.returnInfo.strType = getParamStrType<R>();
    ALMethodInfo::ALParameterInfo param;
    std::string name = "arg0";
    param.description = "arg";
    for (int i = pDesc.parameters.size(); i < 4; ++i) {
      name[3] = i + '1';
      param.name = name;
      pDesc.parameters.push_back(param);
    }
    pDesc.parameters[0].strType =  getParamStrType<P1>();
    pDesc.parameters[1].strType =  getParamStrType<P2>();
    pDesc.parameters[2].strType =  getParamStrType<P3>();
    pDesc.parameters[3].strType =  getParamStrType<P4>();
  }

  template <typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename R>
  void completeAndCheck(R(C::*) (P1, P2, P3, P4, P5), ALMethodInfo & pDesc)
  {
    pDesc.returnInfo.strType = getParamStrType<R>();
    ALMethodInfo::ALParameterInfo param;
    std::string name = "arg0";
    param.description = "arg";
    for (int i = pDesc.parameters.size(); i < 5; ++i) {
      name[3] = i + '1';
      param.name = name;
      pDesc.parameters.push_back(param);
    }
    pDesc.parameters[0].strType =  getParamStrType<P1>();
    pDesc.parameters[1].strType =  getParamStrType<P2>();
    pDesc.parameters[2].strType =  getParamStrType<P3>();
    pDesc.parameters[3].strType =  getParamStrType<P4>();
    pDesc.parameters[4].strType =  getParamStrType<P5>();
  }

  template <typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename R>
  void completeAndCheck(R(C::*) (P1, P2, P3, P4, P5, P6), ALMethodInfo & pDesc)
  {
    pDesc.returnInfo.strType = getParamStrType<R>();
    ALMethodInfo::ALParameterInfo param;
    std::string name = "arg0";
    param.description = "arg";
    for (int i = pDesc.parameters.size(); i < 6; ++i) {
      name[3] = i + '1';
      param.name = name;
      pDesc.parameters.push_back(param);
    }
    pDesc.parameters[0].strType =  getParamStrType<P1>();
    pDesc.parameters[1].strType =  getParamStrType<P2>();
    pDesc.parameters[2].strType =  getParamStrType<P3>();
    pDesc.parameters[3].strType =  getParamStrType<P4>();
    pDesc.parameters[4].strType =  getParamStrType<P5>();
    pDesc.parameters[5].strType =  getParamStrType<P6>();
  }

}
#endif  // _LIBALCOMMON_ALCOMMON_ALMETHODINFO_H_

