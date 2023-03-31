/*****************************************************************************/
/********** !!! WARNING: CODE GENERATED BY TAPROOT. DO NOT EDIT !!! **********/
/*****************************************************************************/

/*
 * Copyright (c) 2022 Advanced Robotics at the University of Washington <robomstr@uw.edu>
 *
 * This file is part of Taproot.
 *
 * Taproot is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Taproot is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Taproot.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef TAPROOT_FUZZY_RULE_TABLE_HPP_
#define TAPROOT_FUZZY_RULE_TABLE_HPP_

#include "modm/math/matrix.hpp"

namespace tap::algorithms
{
/**
 * An interface that outlines what actions a fuzzy rule table should do. In particular, the fuzzy
 * table should perform an update, where it internally updates any necessary state and determines
 * the "best" parameters, then should return the fuzzy gains computed in the update step.
 *
 * @tparam OUTPUTS The number of outputs from the fuzzy table that are computed during the fuzzy
 * update step.
 */
template <uint8_t OUTPUTS>
class FuzzyRuleTableInterface
{
    /**
     * Updates internal state of the fuzzy table and returns the latest values computed by the fuzzy
     * table.
     *
     * @param[in] e Some error (in user-defined units)
     * @param[in] d The derivative of the error (in user-defined units / time)
     */
    virtual modm::Matrix<float, OUTPUTS, 1> performFuzzyUpdate(float e, float d) = 0;
    /// @return The latest values computed by the fuzzy table.
    virtual inline modm::Matrix<float, OUTPUTS, 1> getFuzzyGains() const = 0;
};
}  // namespace tap::algorithms

#endif  // TAPROOT_FUZZY_RULE_TABLE_HPP_
