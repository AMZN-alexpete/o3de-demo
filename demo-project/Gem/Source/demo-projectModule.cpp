
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "demo-projectSystemComponent.h"

namespace demo_project
{
    class demo_projectModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(demo_projectModule, "{DC57FF17-0F2C-4008-B555-E5F4AADA2200}", AZ::Module);
        AZ_CLASS_ALLOCATOR(demo_projectModule, AZ::SystemAllocator, 0);

        demo_projectModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                demo_projectSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<demo_projectSystemComponent>(),
            };
        }
    };
}// namespace demo_project

AZ_DECLARE_MODULE_CLASS(Gem_demo_project, demo_project::demo_projectModule)
