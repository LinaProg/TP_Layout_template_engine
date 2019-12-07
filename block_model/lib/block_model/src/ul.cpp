#include <ul.h>

block_model::Ul::Ul() = default;

block_model::Ul::Ul(const block_model::Ul& src) {
    tag_content.str = src.tag_content.str;
    class_attr.vec = src.class_attr.vec;
    hidden = src.hidden;
    title.str = src.title.str;

    list_content.vec = src.list_content.vec;
}

block_model::Ul::Ul(block_model::Ul&& src) noexcept {
    tag_content.str = std::move(src.tag_content.str);
    class_attr.vec = std::move(src.class_attr.vec);
    hidden = src.hidden;
    title.str = std::move(src.title.str);

    list_content.vec = std::move(src.list_content.vec);

    id_attr = ----id_count;
}

block_model::Ul& block_model::Ul::operator=(const block_model::Ul& src) {
    tag_content.str = src.tag_content.str;
    class_attr.vec = src.class_attr.vec;
    hidden = src.hidden;
    title.str = src.title.str;

    list_content.vec = src.list_content.vec;

    return *this;
}

block_model::Ul::~Ul() = default;

void block_model::Ul::SetTagContent(const block_model::string &new_content) {

}

block_model::string block_model::Ul::MakeHtmlString() const {
    block_model::string result("<ul");

    CheckAttributes(result);

    result + block_model::string("\n");

    for (const auto& it : list_content.vec) {
        result + block_model::string("\t<li>");
        result + it;
        result + block_model::string("</li>\n");
    }

    result + block_model::string("</ul>");

    return result;
}
