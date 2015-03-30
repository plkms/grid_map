/*
 * MinFilter.hpp
 *
 *  Created on: Mar 18, 2015
 *      Author: Martin Wermelinger
 *   Institute: ETH Zurich, Autonomous Systems Lab
 */

#ifndef MINFILTER_HPP
#define MINFILTER_HPP

#include <filters/filter_base.h>

#include <vector>
#include <string>

namespace filters {

/*!
 * Min Filter class that takes the minimum out of different layers of a grid map.
 */
template<typename T>
class MinFilter : public FilterBase<T>
{

 public:
  /*!
   * Constructor
   */
  MinFilter();

  /*!
   * Destructor.
   */
  virtual ~MinFilter();

  /*!
   * Configures the filter from parameters on the Parameter Server
   */
  virtual bool configure();

  /*!
   * Takes the minimum out of different layers of a grid map.
   * @param mapIn gridMap with the different layers to take the min.
   * @param mapOut gridMap with an additional layer containing the sum.
   */
  virtual bool update(const T& mapIn, T& mapOut);

 private:

  //! List of types that are added together
  std::vector<std::string> minTypes_;

  //! map type for summation.
  std::string typeOut_;

};

} /* namespace */

#endif
