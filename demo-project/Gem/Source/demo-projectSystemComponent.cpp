
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "demo-projectSystemComponent.h"

namespace demo_project
{
    void demo_projectSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<demo_projectSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<demo_projectSystemComponent>("demo_project", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void demo_projectSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("demo_projectService"));
    }

    void demo_projectSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("demo_projectService"));
    }

    void demo_projectSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void demo_projectSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    demo_projectSystemComponent::demo_projectSystemComponent()
    {
        if (demo_projectInterface::Get() == nullptr)
        {
            demo_projectInterface::Register(this);
        }
    }

    demo_projectSystemComponent::~demo_projectSystemComponent()
    {
        if (demo_projectInterface::Get() == this)
        {
            demo_projectInterface::Unregister(this);
        }
    }

    void demo_projectSystemComponent::Init()
    {
    }

    void demo_projectSystemComponent::Activate()
    {
        demo_projectRequestBus::Handler::BusConnect();
    }

    void demo_projectSystemComponent::Deactivate()
    {
        demo_projectRequestBus::Handler::BusDisconnect();
    }
}
