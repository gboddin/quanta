var shadow;

$(document).bind('refresh', function() {
    $('#shadow-inside, #shadow-image').off('click').on('click', function () {
        closeShadow();
    });

});

function closeShadow() {
    $('#shadow-outside, .shadow-element').hide();
}

/**
 * Open a shadow (lightbox) with the specified parameters.
 * @param shadow
 */
function openShadow(shadowData) {
    shadow = shadowData;
    if (shadow.widget == undefined) {
        shadow.widget = 'tabs';
    }

    var shadowPath = '/' + ((shadow.node != undefined) ? (shadow.node + '/') : '') + '?shadow=' + JSON.stringify(shadow);
    $('#shadow-item').html('').attr('data-rel', shadow.context).load(shadowPath, function () {
            if (shadow.callback != undefined) {
                shadow.callback();
            }

            $(document).trigger('refresh');

            // Include attached scripts if present.
            if (shadow.attach != undefined) {
                for (i = 0; i < shadow.attach.length; i++) {
                    $.getScript(shadow.attach[i]);
                }
            }

            $('.shadow-title').find('a').on('click', function () {
                if (!($(this).parent().hasClass('enabled'))) {
                    $('.enabled').removeClass('enabled');
                    $(this).parent().addClass('enabled');
                    $('#shadow-content-' + $(this).attr('data-rel')).addClass('enabled');
                }
                return false;
            });
            $(document).trigger('shadow_open');

            $(document).trigger('shadow_' + shadow.context);
        });
    $('#shadow-outside').fadeIn('slow');
}

/**
 * Submit a shadow form.
 */
function submitShadow() {
    $(document).trigger('shadow_' + shadow.context + '_submit');
    var form_items = {};
    $('#shadow-outside').find('input, textarea, select').each(function () {
        var item_name = $(this).attr('name');
        if (form_items[item_name] == undefined) {
            form_items[item_name] = [];
        }
        if ($(this).attr('type') == 'checkbox') {
            form_items[item_name].push($(this).is(':checked') ? $(this).val() : '');
        } else {
            form_items[item_name].push($(this).val());
        }
    });
    var formData = JSON.stringify(form_items);

    action(formData);
}


