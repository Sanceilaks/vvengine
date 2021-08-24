//
// Created by Admin on 23.07.2021.
//

#ifndef VLUASTUDIO_OBSERVER_H
#define VLUASTUDIO_OBSERVER_H

#include <vector>
#include <any>
#include <functional>
#include <map>

namespace observer {
    using observer_fn = std::function<void(const std::any&)>;

    struct base_observer_event_t {
        std::string id;
        observer_fn fn;
    };

    class i_observer  {
        std::map<std::string, std::vector<base_observer_event_t>> events;

        inline bool id_exist(const std::string& event_name, const std::string& id) {
            auto &evs = events[event_name];
            return std::find_if(evs.begin(), evs.end(), [&id](const base_observer_event_t& event) { return event.id == id; }) != evs.end();
        }
        inline auto get_by_id(const std::string& event_name, const std::string& id) {
            auto &evs = events[event_name];
            return std::find_if(evs.begin(), evs.end(), [&id](const base_observer_event_t& event) { return event.id == id; });
        }
    public:
        ~i_observer() {
            remove_all_listeners();
        }

        inline void notify(const std::string& event, std::any event_data) {
            auto &evs = events[event];
            for (auto i = evs.begin(); i < evs.end(); ++i)
                i->fn(event_data);
        }

        inline void add_listener(const std::string& event, const std::string& id, observer_fn fn) {
            if (!id_exist(event, id)) events[event].push_back({id, fn});
        }

        inline void remove_listener(const std::string& event, const std::string& id) {
            if (id_exist(event, id)) events[event].erase(get_by_id(event, id));
        }

        inline void remove_all_listeners() {
            for (auto& i : events)
                for (auto& j : i.second)
                    remove_listener(i.first, j.id);
        }
    };
}

#endif //VLUASTUDIO_OBSERVER_H
