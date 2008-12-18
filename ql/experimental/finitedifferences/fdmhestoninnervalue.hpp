/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2008 Andreas Gaida
 Copyright (C) 2008 Ralph Schreyer
 Copyright (C) 2008 Klaus Spanderen

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file fdmhestoninnervalue.hpp
    \brief calculate the inner value for a given payoff in the Heston model
*/

#ifndef quantlib_fdm_heston_inner_value_hpp
#define quantlib_fdm_heston_inner_value_hpp

#include <ql/experimental/finitedifferences/fdminnervaluecalculator.hpp>

namespace QuantLib {

    class FdmHestonInnerValue : public FdmInnerValueCalculator {

    public:
        FdmHestonInnerValue(const boost::shared_ptr<Payoff>& payoff)
        : payoff_(payoff) {};

        Real innerValue(const Array& location) {
            return payoff_->operator()(std::exp(location[0]));
        };

    private:
        const boost::shared_ptr<Payoff> payoff_;
    };
}

#endif