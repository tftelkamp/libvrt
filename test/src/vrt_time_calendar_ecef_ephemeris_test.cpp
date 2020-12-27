#include <gtest/gtest.h>

#include <cstdint>

#include <vrt/vrt_error_code.h>
#include <vrt/vrt_init.h>
#include <vrt/vrt_time.h>
#include <vrt/vrt_types.h>

static const uint64_t PS_IN_S{1000000000000};

class TimeCalendarEcefEphemerisTest : public ::testing::Test {
   protected:
    void SetUp() override { vrt_init_if_context(&c_); }

    vrt_if_context    c_{};
    vrt_calendar_time cal_{};
};

TEST_F(TimeCalendarEcefEphemerisTest, UnexpectedField) {
    ASSERT_EQ(vrt_time_calendar_ecef_ephemeris(&c_, 0.0, &cal_), VRT_ERR_EXPECTED_FIELD);
}

TEST_F(TimeCalendarEcefEphemerisTest, TsiNone) {
    c_.has.ecef_ephemeris = true;
    ASSERT_EQ(vrt_time_calendar_ecef_ephemeris(&c_, 0.0, &cal_), VRT_ERR_INVALID_TSI);
}

TEST_F(TimeCalendarEcefEphemerisTest, TsiUtcTsfSampleCount) {
    c_.has.ecef_ephemeris                         = true;
    c_.ecef_ephemeris.tsi                         = VRT_TSI_UTC;
    c_.ecef_ephemeris.integer_second_timestamp    = 1608751092;
    c_.ecef_ephemeris.tsf                         = VRT_TSF_SAMPLE_COUNT;
    c_.ecef_ephemeris.fractional_second_timestamp = 8e6;
    ASSERT_EQ(vrt_time_calendar_ecef_ephemeris(&c_, 16e6, &cal_), 0);
    ASSERT_EQ(cal_.year, 120);
    ASSERT_EQ(cal_.mday, 23);
    ASSERT_EQ(cal_.yday, 357);
    ASSERT_EQ(cal_.sec, 12);
    ASSERT_EQ(cal_.min, 18);
    ASSERT_EQ(cal_.hour, 19);
    ASSERT_EQ(cal_.mon, 11);
    ASSERT_EQ(cal_.wday, 3);
    ASSERT_EQ(cal_.ps, PS_IN_S / 2);
}
