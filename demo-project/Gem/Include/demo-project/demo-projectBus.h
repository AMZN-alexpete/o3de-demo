
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace demo_project
{
    class demo_projectRequests
    {
    public:
        AZ_RTTI(demo_projectRequests, "{85B7B106-B50F-4FD5-8E1F-DDAA699A0342}");
        virtual ~demo_projectRequests() = default;
        // Put your public methods here
    };

    class demo_projectBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using demo_projectRequestBus = AZ::EBus<demo_projectRequests, demo_projectBusTraits>;
    using demo_projectInterface = AZ::Interface<demo_projectRequests>;

} // namespace demo_project
