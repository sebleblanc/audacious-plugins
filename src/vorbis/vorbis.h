#ifndef __VORBIS_H__
#define __VORBIS_H__

#include <vorbis/vorbisfile.h>

#include <libaudcore/i18n.h>
#include <libaudcore/plugin.h>

extern ov_callbacks vorbis_callbacks;

class VorbisPlugin : public InputPlugin
{
public:
    static const char about[];
    static const char * const exts[], * const mimes[];

    static constexpr PluginInfo info = {
        N_("Ogg Vorbis Decoder"),
        PACKAGE,
        about
    };

    static constexpr auto iinfo = InputInfo (FlagWritesTag)
        .with_priority (2)  /* medium-high priority (a little slow) */
        .with_exts (exts)
        .with_mimes (mimes);

    constexpr VorbisPlugin () : InputPlugin (info, iinfo) {}

    bool is_our_file (const char * filename, VFSFile & file);
    Tuple read_tuple (const char * filename, VFSFile & file);
    Index<char> read_image (const char * filename, VFSFile & file);
    bool write_tuple (const char * filename, VFSFile & file, const Tuple & tuple);
    bool play (const char * filename, VFSFile & file);
};

#endif                          /* __VORBIS_H__ */
