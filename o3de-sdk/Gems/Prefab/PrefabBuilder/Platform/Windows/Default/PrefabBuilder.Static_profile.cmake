# Generated by O3DE install

set_property(TARGET PrefabBuilder.Static
    APPEND_STRING PROPERTY IMPORTED_LOCATION
        $<$<CONFIG:profile>:${LY_ROOT_FOLDER}/lib/Windows/profile/Default/PrefabBuilder.Static.lib>
)
set_property(TARGET PrefabBuilder.Static
    PROPERTY IMPORTED_LOCATION_PROFILE
        ${LY_ROOT_FOLDER}/lib/Windows/profile/Default/PrefabBuilder.Static.lib
)
