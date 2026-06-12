#include <gtest/gtest.h>

#include "PiSubmarine/Video/Subscription/Grpc/Api/VideoSubscriptionService.h"

namespace PiSubmarine::Video::Subscription::Grpc::Api
{
    TEST(VideoSubscriptionServiceTest, GeneratedServiceTypeExists)
    {
        using Service = ::pisubmarine::video::subscription::grpc::api::VideoSubscriptionService;
        EXPECT_NE(sizeof(Service), 0);
    }
}
