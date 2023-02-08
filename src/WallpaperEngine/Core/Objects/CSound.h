#pragma once

#include "WallpaperEngine/Core/Core.h"
#include "WallpaperEngine/Core/CObject.h"
#include "WallpaperEngine/Core/UserSettings/CUserSettingBoolean.h"

namespace WallpaperEngine::Core::Objects
{
    using json = nlohmann::json;
    using namespace WallpaperEngine::Core::UserSettings;

    class CSound : public CObject
    {
        friend class CObject;

    public:
        static CObject* fromJSON (
            CScene* scene,
            json data,
            CUserSettingBoolean* visible,
            uint32_t id,
            const std::string& name,
            CUserSettingVector3* origin,
            CUserSettingVector3* scale,
            const glm::vec3& angles
        );

        void insertSound (const std::string& filename);
        const std::vector<std::string>& getSounds () const;
        bool isRepeat () const;

    protected:
        CSound (
            CScene* scene,
            CUserSettingBoolean* visible,
            uint32_t id,
            std::string name,
            CUserSettingVector3* origin,
            CUserSettingVector3* scale,
            const glm::vec3& angles,
            bool repeat
        );

        static const std::string Type;
    private:
        bool m_repeat;
        std::vector<std::string> m_sounds;
    };
}
