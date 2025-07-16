
#pragma once

#include <DefaultTemplateGem/DefaultTemplateGemTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace DefaultTemplateGem
{
    class DefaultTemplateGemRequests
    {
    public:
        AZ_RTTI(DefaultTemplateGemRequests, DefaultTemplateGemRequestsTypeId);
        virtual ~DefaultTemplateGemRequests() = default;
        // Put your public methods here
    };

    class DefaultTemplateGemBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using DefaultTemplateGemRequestBus = AZ::EBus<DefaultTemplateGemRequests, DefaultTemplateGemBusTraits>;
    using DefaultTemplateGemInterface = AZ::Interface<DefaultTemplateGemRequests>;

} // namespace DefaultTemplateGem
