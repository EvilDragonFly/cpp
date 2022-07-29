# cpp
learning notes and examples of cpp
lcov -b src -d build/src/ccm/$1 -c -o ut_ccm_$1_${date}_${time}.info --rc lcov_branch_coverage=1
genhtml -o ut_ccm_$1_${date}_${time} ut_ccm_$1_${date}_${time}.info --rc lcov_branch_coverage=1
